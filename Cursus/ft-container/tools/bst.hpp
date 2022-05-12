/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:50:35 by gfaviere          #+#    #+#             */
/*   Updated: 2022/04/11 18:52:55 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include "pair.hpp"
#include "../Iterators/BstIterator.hpp"
#include "../Iterators/ReverseIterator.hpp"
#include "../tools/type_traits.hpp"
#include "../tools/tools.hpp"

namespace ft 
{
	template < class T >
	struct node
	{
		typedef T	value_type;

		value_type	data;
		node		*left;
		node		*right;
		node		*parent;

		node(value_type const &src) : data(src){}
		node(value_type const &src, node *l, node *r, node *p) : data(src), left(l), right(r), parent(p) {}
		node(node *l, node *r, node *p) : left(l), right(r), parent(p) {}
	};


	template <class T, class Compare, class Alloc = std::allocator<node<T> > >
	class bst
	{
		public:
			typedef T		value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;

			typedef size_t	size_type;

			typedef node<value_type>	node;
			typedef node				*node_ptr;

			typedef ft::BstIterator<node>							iterator;
			typedef ft::BstIterator<node>							const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


			bst(const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp){
				_size = 0;
				_root = NULL;
			};

			bst(bst const& copy)
			{
				_alloc = copy._alloc;
				_comp = copy._comp;
				_size = copy._size;
				_deepCopy(*this, copy._root);
			}

			bst operator=(bst const& copy)
			{
				if (this != &copy)
				{
					_alloc = copy._alloc;
					_comp = copy._comp;
					_size = copy._size;
					_deepCopy(*this, copy._root);
				}
				return *this;
			}

			~bst()
			{
				if (_size > 0)
					_deepClear(_root);
				
			}

			iterator begin() {
				if (!_root)
					return end();
				return iterator(_min(_root), _root);
			}

			iterator end() {
				return iterator(NULL, _root);
			}

			bool empty() const {return (_size == 0);}
			size_type size() const {return _size;}
			size_type	max_size() const {return _alloc.max_size();}

			node_ptr research(value_type const& val) const
			{
				node_ptr tmp = _root;

				while (tmp)
				{
					if (val.first == tmp->data.first)
						return tmp;
					else if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					else 
						tmp = tmp->right;
				}
				return NULL;
			}

			ft::pair<iterator, bool> insert(value_type val, node_ptr root)
			{
				node_ptr tmp = root;
				node_ptr buf = NULL;

				while (tmp != NULL)
				{
					buf = tmp;
					
					if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					else if (_comp(tmp->data.first, val.first))
						tmp = tmp->right;
					else
						return ft::make_pair<iterator, bool>(iterator(tmp, _root), false);
				}
				node_ptr n = _new_node(val);
				n->parent = buf;
				if (buf == NULL)
				{
					_root = n;
					_root->parent = NULL;
				}
				else if (_comp(n->data.first, buf->data.first))
					buf->left = n;
				else
					buf->right = n;
				_size++;

				return ft::make_pair<iterator, bool>(iterator(n, _root), true);
			}

			iterator insert (iterator position, const value_type& val){
				node_ptr next = _findNext(position.getCurrent());
				if (_comp(position.getCurrent()->data.first, val.first) && _comp(val.first, next->data.first))
				{
					ft::pair<iterator, bool> r = insert(val, position.getCurrent());
					return r.first;
				}
				else
					return insert(val, _root).first;
			}

			void	erase(iterator position)
			{
				node_ptr tmp = research(*position);
				if (!tmp)
					return ;
				_deepRemove(tmp);
			}

			size_type erase(value_type const &k)
			{
				
				node_ptr tmp = research(k);
				if (tmp)
					_deepRemove(tmp);
				else
					return 0;
				return 1;
			}

			void swap (bst& x){
				node_ptr		tmp_root = _root;
				size_type		tmp_size = _size;
				allocator_type	tmp_alloc = _alloc;
				key_compare		tmp_comp = _comp;

				_root = x._root;
				_size = x._size;
				_alloc = x._alloc;
				_comp = x._comp;

				x._root = tmp_root;
				x._size = tmp_size;
				x._alloc = tmp_alloc;
				x._comp = tmp_comp;
			}

			void	clear()
			{
				_deepClear(_root);
				_size = 0;
				_root = NULL;
			}

			size_type count (const value_type& val) const
			{
				if (research(val))
					return 1;
				return 0;
			}

		iterator lower_bound(const value_type &k)
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k.first, tmp->data.first) || (!_comp(k.first, tmp->data.first) && !_comp(tmp->data.first, k.first)))
					return it;
				it++;
			}
			return it;
		}

		const_iterator lower_bound(const value_type &k) const
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k.first, tmp->data.first) || (!_comp(k.first, tmp->data.first) && !_comp(tmp->data.first, k.first)))
					return it;
				it++;
			}
			return it;
		}

		iterator upper_bound(const value_type &k)
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k.first, tmp->data.first))
					return it;
				it++;
			}
			return it;
		}

		const_iterator upper_bound(const value_type &k) const
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k, tmp->data))
					return it;
				it++;
			}
			return it;
		}

			//Getters
			node_ptr	getRoot() const {return _root;}
			size_type	getSize() const {return _size;}

		private:
			node_ptr		_root;
			size_type		_size;
			allocator_type	_alloc;
			key_compare		_comp;


			void	_deepCopy(bst &dest, node_ptr croot)
			{
				if (croot != NULL)
				{
					_deepCopy(dest, croot->left);
					dest.insert(croot->data, _root);
					_deepCopy(dest, croot->right);
				}
			}

			node_ptr _new_node(const value_type &val)
			{
				node_ptr ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			}

			void		_deepRemove(node_ptr to_remove)
			{
				node_ptr to_replace;
				//two children
				if (to_remove->right && to_remove->left)
				{
					//left side of root
					if (_comp(to_remove->data.first, _root->data.first))
					{
						//to_replace = min of the right side of to_remove
						to_replace = _min(to_remove->right);
						
						node_ptr buf = to_replace->parent;
						//set to_replace parent and left
						to_replace->parent = to_remove->parent;
						to_replace->left = to_remove->left;
						//set to_replace in the tree
						to_remove->parent->left = to_replace;
						to_remove->left->parent = to_replace;

						if (to_remove->right != to_replace)
						{
							to_replace->right = to_remove->right;
							to_remove->right->parent = to_replace;
							if (buf != to_remove)
								buf->left = NULL;
						}
					}
					//right side and root
					else
					{
						//to_replace = max of the left side of to_remove
						to_replace = _max(to_remove->left);

						node_ptr buf = to_replace->parent;
						//set to_replace parent and left
						to_replace->parent = to_remove->parent;
						to_replace->right = to_remove->right;
							
						//set to_replace in the tree
						to_remove->right->parent = to_replace;
						if (to_remove->parent)
							to_remove->parent->left = to_replace;
						if (to_remove->left != to_replace)
						{
							to_replace->left = to_remove->left;
							to_remove->left->parent = to_replace;

							if (buf != to_remove)
								buf->right = NULL;
						}
						if (to_replace->parent == NULL)
							_root = to_replace;
						
					}
				}
				//one child
				else if (to_remove->left)
				{
					to_replace = to_remove->left;

					if (to_remove->parent)
					{
						to_replace->parent = to_remove->parent;
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = to_replace;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = to_replace;
					}
					else
					{
						to_replace->parent = NULL;
						_root = to_replace;
					}
				}
				else if (to_remove->right)
				{
					to_replace = to_remove->right;

					if (to_remove->parent)
					{
						to_replace->parent = to_remove->parent;
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = to_replace;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = to_replace;
					}
					else
					{
						to_replace->parent = NULL;
						_root = to_replace;
					}
				}
				//no child
				else
				{
					if (to_remove != _root)
					{
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = NULL;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = NULL;
					}
				}
				_alloc.destroy(to_remove);
				_alloc.deallocate(to_remove, 1);
				_size--;
			}

			node_ptr	_min(node_ptr root)
			{
				while (root->left != NULL)
					root = root->left;
				return root;
			}

			node_ptr	_max(node_ptr root)
			{
				while (root->right != NULL)
					root = root->right;
				return root;
			}

			void		_deepClear(node_ptr root)
			{
				if (!root)
					return ;
				_deepClear(root->left);
				_deepClear(root->right);
				_alloc.destroy(root);
				_alloc.deallocate(root, 1);
			}

			node_ptr _findNext(node_ptr n)
			{
				node_ptr next = NULL;

				if (n->right != NULL)
					return _min(n->right);

				next = n->parent;
				while (next != NULL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}
	};
}