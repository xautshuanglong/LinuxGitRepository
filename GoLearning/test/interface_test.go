/********************************************************************\
 *  Author: xautshuanglong
 *  Date: 2020-10-10 21:16:02
 *  LastEditor: xautshuanglong
 *  LastEditTime: 2020-11-21 17:39:25
 *  FilePath: /GoLearning/test/interface_test.go
 *  Description:
\********************************************************************/
package unit_test

import "../demo"
import "testing"
import "fmt"

func Test_Animal(t *testing.T) {
    var dogDuk test_demo.Animal
    fmt.Printf("Animal --> %+v\n", dogDuk)
    dogDuk = &test_demo.AnimalDog{
        Name:   "duk",
        Age:    5,
        Weight: 13.4,
    }
    fmt.Printf("Animal --> %+v\n", dogDuk)
    dogDuk.Eat("meat")
    dogDuk.Run()

    var catPen = &test_demo.AnimalCat{
        Name:   "pen",
        Age:    5,
        Weight: 19.4,
    }
    catPen.Eat("meat")
    catPen.Run()

    printAnimalInfo(dogDuk)
    printAnimalInfo(catPen)
}

func printAnimalInfo(animal test_demo.Animal) {
    fmt.Printf("%s : %d years %f kilogram\n", animal.GetName(), animal.GetAge(), animal.GetWeight())
}

func Test_AnimalDog(t *testing.T) {
    dogTony := test_demo.AnimalDog{
        Name:   "tony",
        Age:    3,
        Weight: 15.6,
    }
    dogTony.Eat("meat")
    dogTony.Run()

    var dogBen test_demo.AnimalDog
    dogBen.Name = "ben"
    dogBen.Age = 6
    dogBen.Weight = 14.5
    dogBen.Eat("meat")
    dogBen.Run()

    var dogSony = new(test_demo.AnimalDog)
    dogSony.Name = "sony"
    dogSony.Age = 8
    dogSony.Weight = 20.5
    dogSony.Eat("meat")
    dogSony.Run()

    var dogTest = &test_demo.AnimalDog{
        Name:   "Test",
        Age:    9,
        Weight: 11.4,
    }
    dogTest.Eat("fruit")
    dogTest.Run()

    fmt.Printf("AnimalDog -----> %v %+v\n", dogTony.Name, dogTony)
    fmt.Printf("AnimalDog -----> %v %+v\n", dogBen.Name, dogBen)
    fmt.Printf("AnimalDog -----> %v %+v\n", dogSony.Name, dogSony)
    fmt.Printf("AnimalDog -----> %v %+v\n", dogTest.Name, dogTest)
}

func Test_AnimalCat(t *testing.T) {
    catTony := test_demo.AnimalCat{
        Name:   "tony",
        Age:    3,
        Weight: 15.6,
    }
    catTony.Eat("meat")
    catTony.Run()

    var catBen test_demo.AnimalCat
    catBen.Name = "ben"
    catBen.Age = 6
    catBen.Weight = 14.5
    catBen.Eat("meat")
    catBen.Run()

    var catSony = new(test_demo.AnimalCat)
    catSony.Name = "sony"
    catSony.Age = 8
    catSony.Weight = 20.5
    catSony.Eat("meat")
    catSony.Run()
}

func Test_SecureInterfaceImp(t *testing.T) {
    secureInterface := test_demo.SecureInterfaceImp{
        ID: "TestingInterface",
    }
    secureInterface.PublicMethod()

    printInterfaceTest(secureInterface)
}

func printInterfaceTest(si test_demo.SecureInterface) {
    si.PublicMethod()
}
