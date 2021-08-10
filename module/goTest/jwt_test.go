package main

import (
	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Get("/login/:Username/:Password", login)
	t.Get("/verify/:Token", verify)
}

type JWTclaims struct{
	jwt.StandardClaims
	UserID int `json:"user_id"`
	PassWord	string `json:"password"`
}

func login(c *gin.Context) {
	uname := c.Param("Username")
	pword := c.Param("Password")
	claims := &
}
