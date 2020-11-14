/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-10 20:35:33
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-10-18 20:30:30
 *  FilePath: /GoLearning/test_demo/test_interface.go
 *  Description:
\********************************************************************/
package test_demo

import "fmt"

type Animal interface {
    Eat(food string)
    Run() int
}

type AnimalDog struct {
    Name   string
    Age    int
    Weight float32
}

func (dog AnimalDog) Eat(food string) {
    fmt.Printf("AnimalDog -----> %v eat %v\n", dog.Name, food)
}

func (dog AnimalDog) Run() int {
    fmt.Printf("AnimalDog -----> %v weight %vkg running\n", dog.Name, dog.Weight)
    return 100
}

type AnimalCat struct {
    Name   string
    Age    int
    Weight float32
}

func (dog AnimalCat) Eat(food string) {
    fmt.Printf("AnimalCat -----> %v eat %v\n", dog.Name, food)
}

func (dog AnimalCat) Run() int {
    fmt.Printf("AnimalCat -----> %v weight %vkg running\n", dog.Name, dog.Weight)
    return 100
}
