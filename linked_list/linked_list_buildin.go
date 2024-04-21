package main

import (
	"container/list"
	"fmt"
)

func main() {
	list := list.New()
	list.PushFront(1)
	list.PushFront(3)
	list.PushBack(5)

	fmt.Print("Linked List: ")
	for e := list.Front(); e != nil; e = e.Next() {
		fmt.Printf("%v ", e.Value)
	}
	fmt.Println()

}
