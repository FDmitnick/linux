package main

import (
	"fmt"

	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

// UserInfo 用户信息
type UserInfo struct {
	ID     uint
	Name   string
	Gender string
	Hobby  string
}

//  truncate table 表名
// gorm 需要提前创建数据库gorm1
func main() {
	fmt.Println("try open mysql connection....")
	db, err := gorm.Open("mysql", "root:iam59!z$@(localhost:3306)/test?charset=utf8mb4&parseTime=True&loc=Local")
	if err != nil {
		//fmt.Println("ERROR : gorm open mysql error...." + err)
		panic(err)
	}
	defer db.Close()
	// 自动迁移
	// 若该表不存在则创建该表，若该表存在且结构体发生变化则更新表结构
	db.AutoMigrate(&UserInfo{})
	u1 := UserInfo{1, "0voice", "man", "football"}
	u2 := UserInfo{2, "darren", "men", "basketball"}
	/*
		// 直接插入数据，不涉及ID
		u1=UserInfo{
			Name: "xxx",
			Gender:"man",
			Hobby: "play"
		}*/
	// 创建记录
	result := db.Create(&u1)
	fmt.Println("result:", result.RowsAffected)
	db.Create(&u2)
	// 查询
	var u = new(UserInfo)
	// 读出来第一个记录
	db.First(u)
	fmt.Printf("First: %#v\n", u)
	fmt.Println("u:", u)
	var uu UserInfo
	db.Find(&uu, "hobby=?", "basketball") // 条件查询
	fmt.Printf("Find: %#v\n", uu)
	fmt.Println("uu:", uu)
	// 更新
	db.Model(&uu).Update("hobby", "football")
	// 删除
	db.Delete(&u)
}

// drop table xxx;	// 删除表
// desc xxx; 		// 查看表内容
