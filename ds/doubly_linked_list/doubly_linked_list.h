#ifndef __DS__DOUBLY_LINKED_LIST_H__
#define __DS__DOUBLY_LINKED_LIST_H__

namespace ds
{
	class doubly_linked_list;
	class doubly_linked_list_node;

	class doubly_linked_list_node
	{
	public:
		doubly_linked_list_node *prev;
		doubly_linked_list_node *next;
		doubly_linked_list *owner;

		doubly_linked_list_node(
			doubly_linked_list_node *prev_node,
			doubly_linked_list_node *next_node,
			doubly_linked_list *owner_list) :
		prev(prev_node), next(next_node), owner(owner_list)
		{}
	};

	class doubly_linked_list
	{
	public:
		doubly_linked_list_node *first;
		doubly_linked_list_node *last;

		doubly_linked_list()
		{
			first = nullptr;
			last = nullptr;
		}
		
		void splice(
			doubly_linked_list_node *a, 
			doubly_linked_list_node *b, 
			doubly_linked_list_node *t)
		{
			// asserts
			if (a->owner != b->owner)
				throw("nodes belongs to different lists");
			doubly_linked_list_node *tmp = a;
			do {
				if (tmp->next == b)
					break;
				if (tmp->next == nullptr) {
					throw("b should not be befor a");
					return;
				}
				tmp = tmp->next;
			} while (tmp->next != nullptr);
		}
	};
}

#endif // __DS__DOUBLY_LINKED_LIST_H__