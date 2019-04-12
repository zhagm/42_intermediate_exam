/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.org>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:41:55 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/11 13:16:32 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct				s_node
{
	void			*content;
	struct s_node	*next;
};

struct				s_queue
{
	struct s_node	*first;
	struct s_node	*last;
};

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
	struct s_node	*dequeued;
	void			*content;

	if (queue == NULL)
		return (NULL);
	if (queue->first)
	{
		dequeued = queue->first;
		if (queue->first == queue->last)
			queue->last = NULL;
		queue->first = dequeued->next;
		content = dequeued->content;
		free(dequeued);
		return (content);
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
