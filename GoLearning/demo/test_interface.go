/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-10 20:35:33
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-23 14:48:45
 *  FilePath: /GoLearning/demo/test_interface.go
 *  Description:
\********************************************************************/
package demo

import "fmt"

type Animal interface {
    GetName() string
    GetAge() int
    GetWeight() float32
    Eat(food string)
    Run() int
}

type AnimalDog struct {
    Name   string
    Age    int
    Weight float32
}

func (dog AnimalDog) GetName() string {
    return dog.Name
}

func (dog AnimalDog) GetAge() int {
    return dog.Age
}

func (dog AnimalDog) GetWeight() float32 {
    return dog.Weight
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

func (cat AnimalCat) GetName() string {
    return cat.Name
}

func (cat AnimalCat) GetAge() int {
    return cat.Age
}

func (cat AnimalCat) GetWeight() float32 {
    return cat.Weight
}

func (cat AnimalCat) Eat(food string) {
    fmt.Printf("AnimalCat -----> %v eat %v\n", cat.Name, food)
}

func (cat AnimalCat) Run() int {
    fmt.Printf("AnimalCat -----> %v weight %vkg running\n", cat.Name, cat.Weight)
    return 100
}

type SecureInterface interface {
    PublicMethod()
    privateMethod()
}

type SecureInterfaceImp struct {
    ID string
}

func (si SecureInterfaceImp) PublicMethod() {
    fmt.Printf("Inside func SecureInterfaceImp::PublicMethod ID=%s ...\n", si.ID)
    si.privateMethod()
}

func (si SecureInterfaceImp) privateMethod() {
    fmt.Printf("Inside func SecureInterfaceImp::privateMethod ID=%s ...\n", si.ID)
}
