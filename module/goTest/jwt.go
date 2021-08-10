package main

import (
	"errors"
	"fmt"
	"net/http"
	"time"

	jwt "github.com/dgrijalva/jwt-go"
	"github.com/gin-gonic/gin"
)

// readme := jwt + gin
// 目标 := jwt + gin + gorm

type JWTClaims struct {
	jwt.StandardClaims
	UserID   int    `json:"user_id"`
	Password string `json:"password"`
	Username string `json:"username"`
}

// http://47.112.254.232:8082/login/darren/123456
// http://47.112.254.232:8082/refresh/
func main() {
	r := gin.Default()
	r.GET("/login/:Username/:Password", login)
	r.GET("/verify/:Token", verify)
	_ = r.Run(":8082")
}

type JWTclaims struct {
	jwt.StandardClaims
	UserID   int    `json:"user_id"`
	PassWord string `json:"password"`
	Username string
}

const (
	ErrorServerBusy = "server is busy"
	ErrorReLogin    = "relogin"
)

var (
	Secret     = "123#111" //salt
	ExpireTime = 3600      //token expire time
)

func login(c *gin.Context) {
	uname := c.Param("Username")
	pword := c.Param("Password")
	claims := &JWTClaims{
		UserID:   1,
		Username: uname,
		Password: pword,
	}
	claims.IssuedAt = time.Now().Unix()
	claims.ExpiresAt = time.Now().Add(time.Second * time.Duration(ExpireTime)).Unix()
	singedToken, err := genToken(claims)
	if err != nil {
		c.String(http.StatusNotFound, err.Error())
		return
	}
	c.String(http.StatusOK, singedToken)
}

func verify(c *gin.Context) {
	strToken := c.Param("token")
	claim, err := verifyAction(strToken)
	if err != nil {
		c.String(http.StatusNotFound, err.Error())
		return
	}
	c.String(http.StatusOK, "verify: ", claim.Username)
}

//验证jwt token
func verifyAction(strToken string) (*JWTClaims, error) {
	token, err := jwt.ParseWithClaims(strToken, &JWTClaims{}, func(token *jwt.Token) (interface{}, error) {
		return []byte(Secret), nil
	})

	if err != nil {
		return nil, errors.New(ErrorServerBusy)
	}
	claims, ok := token.Claims.(*JWTClaims)
	if !ok {
		return nil, errors.New(ErrorReLogin)
	}
	if err := token.Claims.Valid(); err != nil {
		return nil, errors.New(ErrorReLogin)
	}
	fmt.Println("verify")
	return claims, nil
}

//generate jwt token
func genToken(claims *JWTClaims) (string, error) {
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	signedToken, err := token.SignedString([]byte(Secret))
	if err != nil {
		return "", errors.New(ErrorServerBusy)
	}
	return signedToken, nil
}
