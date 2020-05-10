package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func KthToTail(head *ListNode, k int) *ListNode {
	if head == nil || k <= 0 {
		return nil
	}
	front := head
	var back *ListNode
	for i := 0; i < k - 1; i++ {
		if front.Next == nil {
			return nil
		}
		front = front.Next
	}

	back = head
	for front.Next != nil {
		front, back = front.Next, back.Next
	}
	return back
}

func main() {
	node1 := &ListNode{1, nil}
	node2 := &ListNode{2, nil}
	node1.Next = node2
	node3 := &ListNode{3, nil}
	node2.Next = node3
	node4 := &ListNode{4, nil}
	node3.Next = node4
	node5 := &ListNode{5, nil}
	node4.Next = node5
	node6 := &ListNode{6, nil}
	node5.Next = node6
	node7 := &ListNode{7, nil}
	node6.Next = node7

	fmt.Println(KthToTail(node1, 7).Val)
}
