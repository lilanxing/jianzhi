package main

import (
	"fmt"
)

type listNode struct {
	val  int
	next *listNode
}

func printList(head *listNode) {
	nodes := make([]*listNode, 0)
	p := head
	for p != nil {
		nodes = append(nodes, p)
		p = p.next
	}
	for i := len(nodes) - 1; i >= 0; i-- {
		fmt.Printf("%d ", nodes[i].val)
	}
	fmt.Printf("\n")
}

func printList2(head *listNode) {
	if head == nil {
		return
	}
	if head.next != nil {
		printList2(head.next)
	}
	fmt.Printf("%d ", head.val)
}

func main() {
	node1 := &listNode{1, nil}
	node2 := &listNode{2, nil}
	node1.next = node2
	node3 := &listNode{3, nil}
	node2.next = node3

	printList(node1)
	printList2(node1)
	fmt.Printf("\n")
}
