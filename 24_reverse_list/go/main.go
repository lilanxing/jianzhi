package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func ReverseList(head *ListNode) *ListNode {
	var (
		reversedHead *ListNode
		prevNode     *ListNode
		p            *ListNode
	)
	p = head

	for p != nil {
		pNext := p.Next
		if pNext == nil {
			reversedHead = p
		}

		p.Next = prevNode
		prevNode = p
		p = pNext
	}
	return reversedHead
}

func outputList(head *ListNode) {
	for p := head; p != nil; p = p.Next {
		fmt.Printf("%d ", p.Val)
	}
	fmt.Printf("\n")
}

func main() {
	node1 := &ListNode{1, nil}
	node2 := &ListNode{2, nil}
	node1.Next = node2
	node3 := &ListNode{3, nil}
	node2.Next = node3
	node4 := &ListNode{4, nil}
	node3.Next = node4

	outputList(node1)
	outputList(ReverseList(node1))
}
