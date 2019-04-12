/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.org>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:41:55 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/11 13:14:13 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>
#include "queue.h"

struct s_queue	*init(void)
{
	struct s_queue	*new;

	new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new;

	if (queue == NULL)
		return ;
	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (queue->last)
	{
		queue->last->next = new;
		queue->last = new;
	}
	else
	{
		queue->first = new;
		queue->last = new;
	}
}

void	*dequeue(struct s_queue *queue)
{
	struct s_node *dequeued;

	if (queue == NULL)
		return (NULL);
	if (queue->first)
	{
		dequeued = queue->first;
		if (queue->first == queue->last)
			queue->last = NULL;
		queue->first = dequeued->next;
		return (dequeued);
	}
	return (NULL);
}

void	*peek(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);
	return (queue->first);
}

int		isEmpty(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (1);
	return (0);
}

void	print_queue(struct s_queue *q)
{
	struct s_node *curr;

	if (!q)
		return;
	curr = q->first;
	while (curr)
	{
		printf("(%s)-->", curr->content);
		curr = curr->next;
	}
	printf("NULL\n");
}

int		main(void)
{
	struct s_queue *q;
	char *str = "HELLO";
	char *str2 = "OLLEH";

	q = init();
	printf("INIT: %s\n", q != NULL ? "PASS" : "FAIL");
	enqueue(q, str);
	enqueue(q, str2);
	printf("ENQUEUE: %s\n", q->last != NULL ? "PASS" : "FAIL");
	print_queue(q);
	printf("DEQUEUE: %s\n", dequeue(q) ? "PASS" : "FAIL");
	print_queue(q);
	printf("PEEK: %s\n", peek(q) ? "PASS" : (q->first ? "FAIL" : "PASS"));
	printf("ISEMPTY: %s\n", (!isEmpty(q) && dequeue(q) && isEmpty(q)) ? "PASS" : "FAIL");
	print_queue(q);
	printf("PEEK: %s\n", peek(q) ? "FAIL" : "PASS");
	printf("DEQUEUE: %s\n", dequeue(q) ? "FAIL" : "PASS");
	enqueue(q, str2);
	enqueue(q, str);
	print_queue(q);
	return (0);
}
