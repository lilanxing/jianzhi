package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func MeetingNode(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	slow := head.Next
	if slow == nil {
		return nil
	}
	fast := slow.Next

	for fast != nil || slow != nil {
		if fast == slow {
			return fast
		}
		if fast, slow = fast.Next, slow.Next; fast != nil {
			fast = fast.Next
		}
	}
	return nil
}

func EntryLoop(head *ListNode) *ListNode {
	meetingNode := MeetingNode(head)
	if meetingNode == nil {
		return nil
	}
	p, loopInnerCount := meetingNode, 1
	for ; p.Next != meetingNode; p = p.Next {
		loopInnerCount++
	}

	p, back := head, head
	for i := 0; i < loopInnerCount; i++ {
		p = p.Next
	}
	for p != back {
		p, back = p.Next, back.Next
	}
	return p
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
	node6.Next = node1

	if entryNode := EntryLoop(node1); entryNode == nil {
		fmt.Println("no loop")
	} else {
		fmt.Printf("entry loop: %d\n", entryNode.Val)
	}
}
