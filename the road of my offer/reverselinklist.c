struct ListNode
{
	int value;
	ListNode *next;
};

ListNode reverseLinkList(ListNode *list)
{
	ListNode *tmp = NULL;
	ListNode *p = NULL;

	if(list == NULL)
	{
		printf("链表为空\n");
	}	

	tmp = list;
	tmp->next = NULL;

	while(list->next != NULL)
	{
		p = list->next;
		list = list->next;
		p->next = tmp;
		tmp = p;
		
	}

	return tmp;
}