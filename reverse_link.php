<?php
#反转链表：https://leetcode-cn.com/problems/reverse-linked-list/
class ListNode
{
    public $val = 0;
    public $next = null;

    function __construct($val = 0, $next = null)
    {
        $this->val = $val;
        $this->next = $next;
    }
}

function reverseLink(ListNode $head)
{
    $prev = null;

    $current = $head;

    while ($current) {

        $next = $current->next;

        $current->next = $prev;

        $prev = $current;

        $current = $next;
    }

    return $prev;
}
