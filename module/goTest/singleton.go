// 单例模式
package main

import (
	"fmt"
	"sync"
)

type singleton struct {
	name string
}

var ins *singleton
var once sync.Once

func GetIns() *singleton {
	once.Do(func() {
		ins = &singleton{}
		ins.name = "zmz"
	})
	return ins
}

func main() {
	s := GetIns()
	fmt.Println(s.name)
}
