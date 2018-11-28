#include<stdio.h>
#include<stdlib.h>
#include "list.h"

struct My_DATA {
	int Data_A;
	int Data_B;
	int Data_C;
	struct list_head list;
};

void print_List(struct list_head *head){
	struct list_head *listptr;
	struct My_DATA *entry;
 
	printf("\n******************************list_for_each*******************************************\n");
	printf("(HEAD addr = %p, next = %p, prev = %p)\n",head, head->next, head->prev);
	list_for_each(listptr, head) {
        	entry = list_entry(listptr, struct My_DATA, list);
		printf("entry->Data_A= %4d | list addr = %p | next = %p | prev = %p\n",
			entry->Data_A, 
			&entry->list, 
			entry->list.next,  
			entry->list.prev  );
	}
	printf("**************************************************************************************\n");
}

void print_List_prev(struct list_head *head){
	struct list_head *listptr;
	struct My_DATA *entry;
 
	printf("\n******************************list_for_each_prev**************************************\n");
	printf("(HEAD addr = %p, next = %p, prev = %p)\n",head, head->next, head->prev);
	list_for_each_prev(listptr, head) {
        	entry = list_entry(listptr, struct My_DATA, list);
		printf("entry->Data_A= %4d | list addr = %p | next = %p | prev = %p\n",
			entry->Data_A, 
			&entry->list, 
			entry->list.next,  
			entry->list.prev  );
	}
	printf("**************************************************************************************\n");
}

struct My_DATA *add_Node_tail(struct list_head *head){
	struct My_DATA *entry;
	entry=(struct My_DATA*)malloc(sizeof(struct My_DATA));
	list_add_tail(&entry->list,head);
	printf("\nAdd Node Tail: Data_A=%4d (list %p, next %p, prev %p)",
		entry->Data_A,
		&entry->list,
		entry->list.next,
		entry->list.prev);
	return entry;
}

struct My_DATA *add_Node(struct list_head *head){
	struct My_DATA *entry;
	entry=(struct My_DATA*)malloc(sizeof(struct My_DATA));
	list_add(&entry->list,head);
	return entry;
}

void remove_Node(struct My_DATA *entry){
	printf("\nRemove: Data_A=%4d (list %p, next %p, prev %p)",
		entry->Data_A,
		&entry->list,
		entry->list.next,
		entry->list.prev);
	list_del(&entry->list);
	free(entry); 
}

void free_List(struct list_head *head)
{
	struct list_head *listptr;
	struct My_DATA *entry;
 
	list_for_each(listptr, head) {
		entry = list_entry(listptr, struct My_DATA, list);
		printf("Free: entry->Data_A = %4d | list addr = %p | next = %p | prev = %p\n",
			entry->Data_A,
			&entry->list,
			entry->list.next,
			entry->list.prev);
		free(entry);
		entry = NULL;
	}
}

int main(int argc, char **argv)
{
	struct My_DATA *itemPtr_1;
	struct My_DATA *itemPtr_2;
	struct My_DATA *itemPtr_3;
	struct My_DATA *itemPtr_4;

	LIST_HEAD(HEAD);
	itemPtr_1 = add_Node(&HEAD);
	itemPtr_1->Data_A = 100;
	itemPtr_2 = add_Node(&HEAD);
	itemPtr_2->Data_A = 200;
	itemPtr_3 = add_Node(&HEAD);
	itemPtr_3->Data_A = 300;
	itemPtr_4 = add_Node(&HEAD);
	itemPtr_4->Data_A = 400;
	print_List(&HEAD);
	print_List_prev(&HEAD);
	remove_Node(itemPtr_3);
	print_List(&HEAD);    
        itemPtr_3 = add_Node(&HEAD);
        itemPtr_3->Data_A = 500;
        print_List(&HEAD);
	remove_Node(itemPtr_2);
	print_List(&HEAD);    
	itemPtr_2 = add_Node_tail(&HEAD);
	itemPtr_2->Data_A = 600;
	print_List(&HEAD);
	free_List(&HEAD);
	return 0;
}

