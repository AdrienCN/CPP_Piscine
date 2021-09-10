#ifndef MAP_HPP
# define MAP_HPP
# include "utils.hpp"
# include "Lexicographic.hpp"
# include <functional>
# include "Iterators.hpp"
# include <iterator>
#ifndef nullptr
# define nullptr NULL
#endif

//red black tree define
#define RED true
#define BLACK false
#define BG_RED   "\x1b[41m"
#define BG_BLACK "\x1b[40m"
#define BG_WHITE "\x1b[47m"
#define BG_RESET "\x1b[0m"
namespace ft
{
	template <class T>
	struct remove_const
	{
	typedef T type;
	};

	template <class T>
	struct remove_const<const T>
	{
	typedef T type;
	};

	//std::pair reimplementation
	template<typename T1, typename T2>
	struct pair
	{
		//remove const
		typedef typename remove_const<T1>::type type1;
		typedef typename remove_const<T2>::type type2;
		type1 first;
		type2 second;
		pair() : first(), second() {}

		pair(const type1& x, const type2& y)
			: first(x), second(y)
		{
		}
		template<typename U, typename V>
		pair(const pair<U, V>& rhs)
			: first(rhs.first), second(rhs.second)
		{
		}
		pair(const pair& rhs)
			: first(rhs.first), second(rhs.second)
		{
		}
		//https://en.cppreference.com/w/cpp/utility/pair/operator%3D
		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
			return *this;
		}
	
		template<typename U, typename V>
		pair& operator=(const pair<U, V>& rhs)
		{
			first = rhs.first;
			second = rhs.second;
			return *this;
		}

		//friend std::swap overload
		friend void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs)
		{
			ft::swap(lhs.first, rhs.first);
			ft::swap(lhs.second, rhs.second);
		}

		void swap(pair& rhs)
		{
			ft::swap(first, rhs.first);
			ft::swap(second, rhs.second);
		}
	};
	//std::pair comparison operators       
	template<typename T1, typename T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template<typename T1, typename T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}
	template<typename T1, typename T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	template<typename T1, typename T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}
	template<typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}
	template<typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}
	//std::pair swap friend
	template<typename T1, typename T2>
	void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs)
	{
		ft::swap(lhs.first, rhs.first);
		ft::swap(lhs.second, rhs.second);
	}
	//std::make_pair
	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}
	//https://en.cppreference.com/w/cpp/container/map
	//implementation of std::map with a red-black tree
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		private:
			//allocator
			Allocator _alloc;
			//Node definition
			struct Node
			{
				//typedef value_type
				typedef pair<const Key, T> value_type;
				//typedef pointer
				typedef value_type* pointer;
				//typedef const_pointer
				typedef const value_type* const_pointer;
				//typedef reference
				typedef value_type& reference;
				//typedef const_reference
				typedef const value_type& const_reference;
				value_type data;
				Node* left;
				Node* right;
				Node* parent;
				bool color;
				Node(const value_type& x, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr, bool c = RED) : data(x), left(l), right(r), parent(p), color(c) {}
			};
			//Node pointer definition
			typedef Node* NodePtr;
			//Node pointer definition
			typedef const Node* ConstNodePtr;
			//node allocator for Node with rebind
			typedef typename Allocator::template rebind<Node>::other node_allocator;
			//_node_allocator
			node_allocator _node_allocator;
			//node allocator for Node with rebind
			//root
			NodePtr root;
			//using a super_root to be able to know when iteration is over
			//https://stackoverflow.com/questions/12684191/implementing-an-iterator-over-binary-or-arbitrary-tree-using-c-11
			NodePtr super_root;
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const Key, T> value_type;
			//size_type
			typedef typename Allocator::size_type size_type;
			//difference_type
			typedef typename Allocator::difference_type difference_type;
			//key_compare
			typedef Compare key_compare;	
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			//iterator definition
			class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
			{
				private:
					NodePtr node;
				public:
					iterator() : node(nullptr) {}
					iterator(NodePtr x) : node(x) {}
					iterator(const iterator& x) : node(x.node)  {}
					iterator& operator=(const iterator& x)
					{
						node = x.node;
						return *this;
					}
					//dereference
					reference operator*() const
					{
						return node->data;
					}
					//arrow
					value_type * operator->() const
					{
						return &(node->data);
					}
					//prefix increment
					iterator& operator++()
					{
						if (node->parent == nullptr)
						{
							return *this;
						}
						if (node->right != 0) 
						{
							node = node->right;
							while (node->left != 0)
							{
								node = node->left;
							}
						}
						else
						{
							NodePtr y = node->parent;
							while (node == y->right)
							{
								node = y;
								y = y->parent;
							}
							if (node->right != y)
								node = y;
						}
						return *this;
					}
					//postfix increment
					iterator operator++(int)
					{
						iterator tmp(*this);
						++(*this);
						return tmp;

					}
					//prefix decrement
					iterator& operator--()
					{
						if (node->left != nullptr)
						{
							node = node->left;
							while (node->right != nullptr)
							{
								node = node->right;
							}
						}
						else
						{
							NodePtr y = node->parent;
							while (node == y->left)
							{
								node = y;
								y = y->parent;
							}
							if (node->left != y)
								node = y;
						}
						return *this;
					}
					//postfix decrement
					iterator operator--(int)
					{
						iterator tmp(*this);
						--(*this);
						return tmp;
					}


					//equality
					bool operator==(const iterator& x) const
					{
						if (node == nullptr && x.node == nullptr)
							return true;
						if (node == nullptr || x.node == nullptr)
							return false;
						return node == x.node;
					}
					//inequality
					bool operator!=(const iterator& x) const
					{
						return !(*this == x);
					}
							//<< iterator
			};

			//const_iterator
			typedef iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef const ft::reverse_iterator<iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<pointer>::iterator_category iterator_category;
			
			private:
			//new_node()
			NodePtr new_node(const value_type& value)
			{
				NodePtr node = _node_allocator.allocate(1);
				_node_allocator.construct(node, value);
				return node;
			}
			//delete_node()
			void delete_node(NodePtr node)
			{
				_node_allocator.destroy(node);
				_node_allocator.deallocate(node, 1);
			}
			public:
			//begin
			iterator begin()
			{
				NodePtr tmp = root;
				while (tmp->left)
					tmp = tmp->left;
				return iterator(tmp);
			}
			//end
			iterator end()
			{
				return iterator(super_root);
			}
			//const iterator
			const_iterator begin() const
			{
				NodePtr tmp = root;
				if (tmp == nullptr)
					return end();
				while (tmp->left)
					tmp = tmp->left;
				return const_iterator(tmp);
			}
			//const end
			const_iterator end() const
			{
				return const_iterator(super_root);
			}
			/*Member classes
			value_compare
			
			compares objects of type value_type
			(class)
			*/
			class value_compare
			{
				friend class map<Key, T, Compare, Allocator>;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					//result type
					typedef bool result_type;
					//first argument type
					typedef value_type first_argument_type;
					//second argument type
					typedef value_type second_argument_type;
					//constructor
					value_compare(const value_compare& x) : comp(x.comp) {}
					
					bool operator()(const value_type& lhs, const value_type& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}
					bool operator()(const value_type& lhs, const Key& rhs) const
					{
						return comp(lhs.first, rhs);
					}
					bool operator()(const Key& lhs, const value_type& rhs) const
					{
						return comp(lhs, rhs.first);
					}
			};
			private:
				Compare comp;

			public:
			//constructors
			//https://en.cppreference.com/w/cpp/container/map/map
			map() : root(nullptr) , super_root(nullptr) {}
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
			: _alloc(alloc), comp(comp), root(nullptr) , super_root(nullptr) {}

			template< class InputIt >
			map( InputIt first, InputIt last,  const Compare& comp = Compare(),  const Allocator& alloc = Allocator() )
			: _alloc(alloc), comp(comp), root(nullptr), super_root(nullptr)
			{
				for(; first != last; ++first)
					insert(*first);
			}
			//clone
			NodePtr clone(ConstNodePtr node) const
			{
				if (node)
					return this->new_node(Node(node->data, clone(node->left), clone(node->right), clone(node->parent), node->color));
				return nullptr;
			}

			map( const map& other )
			: _alloc(other._alloc), root(nullptr), super_root(nullptr), comp(other.comp)
			{
				for (iterator it = other.begin(); it != other.end(); ++it)
					insert(*it);
			}

			//clear();
			void clear()
			{
				if (super_root)
				{
					clear(super_root);
					super_root = nullptr;
					root = nullptr;
				}
			}
			private:
				void clear(NodePtr node)
				{
					if (node)
					{
						clear(node->left);
						clear(node->right);
						delete_node(node);
					}
				}
			public:
			//destructors
			~map()
			{
				clear();
			}
			//assignment operator
			map& operator=(const map& other)
			{
				clear();
				for (iterator it = other.begin(); it != other.end(); ++it)
					insert(*it);
				return *this;
			}
			//size
			size_type size() const
			{
				return size(root);
			}
			private:
				size_type size(ConstNodePtr node) const
				{
					if (node)
						return size(node->left) + size(node->right) + 1;
					return 0;
				}
			public:
			//empty
			bool empty() const
			{
				return root == nullptr;
			}
			//max_size
			size_type max_size() const
			{
				return size_type(-1) / sizeof(Node);
			}
			//find
			iterator find(const key_type& key)
			{
				NodePtr tmp = find(root, key);
				if (tmp)
					return iterator(tmp);
				return end();
			}
			const_iterator find(const key_type& key) const
			{
				NodePtr tmp = find(root, key);
				if (tmp)
					return const_iterator(tmp);
				return end();
			}
			private:
				ConstNodePtr find(ConstNodePtr node, const key_type& key) const
				{
					if (node)
					{
						if (comp(key, node->data.first))
							return find (node->left, key);
						else if (comp(node->data.first, key))
							return find(node->right, key);
						else
							return node;
					}
					return nullptr;
				}
				NodePtr find(NodePtr node, const key_type& key)
				{
					if (node)
					{
						if (comp(key, node->data.first))
							return find(node->left, key);
						else if (comp(node->data.first, key))
							return find(node->right, key);
						else
							return node;
					}
					return nullptr;
				}
			public:
			//lower_bound
			iterator lower_bound(const key_type& key)
			{
				return iterator(lower_bound(root, key));
			}
			const_iterator lower_bound(const key_type& key) const
			{
				return const_iterator(lower_bound(root, key));
			}
			private:
				ConstNodePtr lower_bound(ConstNodePtr node, const key_type& key) const
				{
					if (node)
					{
						if (comp(key, node->data.first))
							return lower_bound(node->left, key);
						else
							return lower_bound(node->right, key);
					}
					return nullptr;
				}
			public:
			//upper_bound
			iterator upper_bound(const key_type& key)
			{
				return iterator(upper_bound(root, key));
			}
			const_iterator upper_bound(const key_type& key) const
			{
				return const_iterator(upper_bound(root, key));
			}
			private:
				ConstNodePtr upper_bound(ConstNodePtr node, const key_type& key) const
				{
					if (node)
					{
						if (comp(key, node->data.first))
							return upper_bound(node->left, key);
						else
							return upper_bound(node->right, key);
					}
					return nullptr;
				}
			public:
			//equal_range https://en.cppreference.com/w/cpp/container/map/equal_range
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{
				return ft::pair<iterator, iterator>(iterator(lower_bound(key)), iterator(upper_bound(key)));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{
				return ft::pair<const_iterator, const_iterator>(const_iterator(lower_bound(key)), const_iterator(upper_bound(key)));
			}
			//insert red black tree
			iterator insert(const value_type& value)
			{
				if (!root)
				{
					root = new_node(value);
					root->color = BLACK;
					super_root = new_node(value);
					super_root->left = root;
					root->parent = super_root;
					return iterator(root);
				}
				return iterator(insert(root, value));
			}
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				if (root == nullptr)
				{
					root = *first;
					root->color = BLACK;
					super_root = new_node(first);
					super_root->left = root;
					root->parent = super_root;
					++first;
				}
				for (; first != last; ++first)
					insert(*first);
			}
			public:
			iterator erase(const_iterator first, const_iterator last)
			{
				while (first != last)
					first = erase(first);
				return iterator(first.node);
			}
			private:
				bool getColor(NodePtr node) const
				{
					return node ? node->color : BLACK;
				}
				//binary tree insert
				NodePtr insert(NodePtr &node, NodePtr new_node)
				{
					if (!node)
					{
						node = new_node;
						node->parent = super_root;
						balance(node);
						return new_node;
					}
					if (comp(new_node->data.first, node->data.first))
					{
						if (!node->left)
						{
							node->left = new_node;
							node->left->parent = node;
							balance(new_node);
							return new_node;
						}
						insert(node->left, new_node);
						balance(new_node);
						return new_node;
					}
					else if (comp(node->data.first, new_node->data.first))
					{
						if (node->right == nullptr)
						{
							node->right = new_node;
							node->right->parent = node;
							balance(new_node);
							return new_node;
						}
						insert(node->right, new_node);
						balance(new_node);
						return new_node;
					}
					else
						delete new_node;
					balance(node);
					return node;
				}

				iterator insert( iterator hint, const value_type& value )
				{
					return iterator(insert(hint.node, new_node(value)));
				}


				//red black tree balance with super_root
				void balance(NodePtr node)
				{
					if (node == super_root)
						return;
					if (node->parent == super_root)
					{
						node->color = BLACK;
						return;
					}
					if (getColor(node->parent) == BLACK)
						return;
					NodePtr parent = node->parent;
					NodePtr grand_parent = parent->parent;
					NodePtr uncle = getUncle(node);
					if (getColor(uncle) == RED)
					{
						parent->color = BLACK;
						uncle->color = BLACK;
						grand_parent->color = RED;
						balance(grand_parent);
					}
					else
					{
						if (node == parent->right && parent == grand_parent->left)
						{
							rotate_left(parent);
							node = node->left;
						}
						else if (node == parent->left && parent == grand_parent->right)
						{
							rotate_right(parent);
							node = node->right;
						}
						parent->color = BLACK;
						grand_parent->color = RED;
						if (node == parent->left)
							rotate_right(grand_parent);
						else
							rotate_left(grand_parent);
					}
				}
				//get uncle
				NodePtr getUncle(NodePtr node)
				{
					if (node->parent == node->parent->parent->left)
						return node->parent->parent->right;
					return node->parent->parent->left;
				}
				//rotate left
				void rotate_left(NodePtr node)
				{
					//std::cout << "rotate left " << (void*)node << std::endl;
					if (node->right == nullptr)
						return;
					NodePtr right = node->right;
					node->right = right->left;
					if (right->left)
						right->left->parent = node;
					right->parent = node->parent;
					if (node->parent == super_root)
						super_root = right;
					else if (node == node->parent->left)
						node->parent->left = right;
					else
						node->parent->right = right;
					right->left = node;
					node->parent = right;
				}
				//rotate right
				void rotate_right(NodePtr node)
				{
					//std::cout << "rotate right " << (void*)node << std::endl;
					NodePtr left = node->left;
					node->left = left->right;
					if (left->right)
						left->right->parent = node;
					left->parent = node->parent;
					if (node->parent == super_root)
						super_root = left;
					else if (node == node->parent->left)
						node->parent->left = left;
					else
						node->parent->right = left;
					left->right = node;
					node->parent = left;
				}
			/*//remove_node_ref
			//search all reference to given node in tree and removes them
				void remove_node_ref(NodePtr node, NodePtr to_remove)
				{
					if (node == nullptr)
						return;
					if (node == to_remove)
					{
						if (node->left)
							node->left->parent = node->parent;
						if (node->right)
							node->right->parent = node->parent;
						if (node->parent == super_root)
							super_root = node->left ? node->left : node->right;
						else if (node == node->parent->left)
							node->parent->left = node->left ? node->left : node->right;
						else
							node->parent->right = node->left ? node->left : node->right;
						return;
					}
				}
			*/
			
			public:
			//erase
			size_type erase( const key_type& key )
			{
				NodePtr node = find(root, key);
				if (node)
				{
					erase(node);
					return 1;
				}
				return 0;
			}
			private:
				void erase(NodePtr node)
				{
					root->parent = nullptr;
					if (node->left && node->right)
					{
						NodePtr successor = node->right;
						while (successor->left)
							successor = successor->left;
						node->data = successor->data;
						node = successor;
					}
					NodePtr child = node->left ? node->left : node->right;
					if (child)
					{
						child->parent = node->parent;
						if (node->parent)
						{
							if (node->parent->left == node)
								node->parent->left = child;
							else
								node->parent->right = child;
						}
						else
							root = child;
					}
					else if (node->parent)
					{
						if (node->parent->left == node)
							node->parent->left = nullptr;
						else
							node->parent->right = nullptr;
					}
					else
					{
						root = nullptr;
						super_root = nullptr;
					}
					if (root == node)
					{
						root = nullptr;
						super_root = nullptr;
					}
					if (super_root == node)
						super_root = nullptr;
					if (super_root->left == node)
						super_root->left = nullptr;
					else if (super_root->right == node)
						super_root->right = nullptr;
					delete_node(node);

					if (root)
					{
						root->parent = super_root;
					}
					super_root->left = root;
				}

			//swap
			void swap(const_reference other)
			{
				ft::swap(root, other.root);
				ft::swap(comp, other.comp);
			}
			public:
			//get_allocator
			allocator_type get_allocator() const
			{
				return allocator_type();
			}
			//at
			reference at(const key_type& key)
			{
				NodePtr node = find(root, key);
				if (!node)
					throw std::out_of_range("out of range");
				return node->data.second;
			}
			const_reference at(const key_type& key) const
			{
				NodePtr node = find(root, key);
				if (!node)
					throw std::out_of_range("out of range");
				return node->data.second;
			}
			//specializes the std::swap algorithm
			friend void swap(map& lhs, map& rhs)
			{
				lhs.swap(rhs);
			}
			friend bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			friend bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return !(lhs == rhs);
			}
			friend bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			friend bool operator<=( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return !(rhs < lhs);
			}
			friend bool operator>( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return rhs < lhs;
			}
			friend bool operator>=( const ft::map<Key,T,Compare,Allocator>& lhs,
							const ft::map<Key,T,Compare,Allocator>& rhs )
			{
				return !(lhs < rhs);
			}

			//[] operator
			//https://en.cppreference.com/w/cpp/container/map/operator_bracket
			/*
			Returns a reference to the mapped value of the element with key equivalent to key.

			If no such element exists, an exception of type std::out_of_range is thrown.
			*/
			mapped_type& operator[](const key_type& key)
			{
				//std::cout << *this << std::endl;
				if (!root)
				{
					//rebind
					root = new_node(value_type(key, mapped_type()));
					//super_root = new_node(ft::make_pair(key, mapped_type()));
					super_root = new_node(ft::make_pair(key, mapped_type()));
					super_root->left = root;
					root->parent = super_root;
					return root->data.second;
				}
				NodePtr node = find(root, key);
				if (!node)
				{
					node = insert(root, new_node(value_type(key, mapped_type())));
				}
				assert(node->data.first == key);
				if (super_root->parent)
				{
					root = super_root;
					super_root = super_root->parent;
					super_root->left = root;
				}
				return node->data.second;
			}
			//<< node
			/*
			friend std::ostream& operator<<(std::ostream& os, NodePtr node)
			{
				if (node)
				{
					os << (node->color ? BG_RED : BG_BLACK) << (void *)node->parent << "^(" << node->data.first << "," << node->data.second << "):" << (void *)node << BG_RESET;
				}
				return os;
			}
			//print_tree
			void print_tree(const std::string& prefix, const NodePtr node, bool isLeft) const
			{
				if( node != nullptr )
				{
					std::cout << prefix;
 
					std::cout << (isLeft ? "├──" : "└─────────────" );
					// print the value of the node
					std::cout << node << std::endl;
					std::cout <<  ( prefix + (isLeft ? "│   │" : "           ")) << std::endl;

					// enter the next tree level - left and right branch
					print_tree( prefix + (isLeft ? "│   " : "              "), node->left, true);
					print_tree( prefix + (isLeft ? "│   " : "              "), node->right, false);
				}
				else
				{
					std::cout << prefix + "└───" BG_BLACK "NULL" BG_RESET << std::endl;
					std::cout <<  ( prefix + (isLeft ? "│   " : "           ")) << std::endl;
				}
			}
			//single arg
			void print_tree(NodePtr node) const
			{
				print_tree("", node, true);
			}
			//stream
			friend std::ostream& operator<<(std::ostream& os, const ft::map<Key,T,Compare,Allocator>& m)
			{
				m.print_tree(m.super_root);
				return os;
			}
			*/
			NodePtr insert(NodePtr node, const value_type& value)
			{
				//NodePtr newNode = new_node(value);
				NodePtr newNode = new_node(value);
				if (!node)
				{
					node = newNode;
					return node;
				}
				newNode = insert(node, newNode);
				if (super_root->parent)
				{
					root = super_root;
					super_root = super_root->parent;
					super_root->left = root;
				}
				return newNode;
			}

			/*//binary tree insert
			NodePtr insert(NodePtr node, const value_type& value)
			{
				if (!node)
				{
					node = new_node(value);
					return node;
				}
				if (comp(value.first, node->data.first))
				{
					if (!node->left)
					{
						node->left = new_node(value);
						node->left->parent = node;
						return node->left;
					}
					return insert(node->left, value);
				}
				else if (comp(node->data.first, value.first))
				{
					if (node->right == nullptr)
					{
						node->right = new_node(value);
						node->right->parent = node;
						return node->right;
					}
					return insert(node->right, value);
				}
				return node;
			}*/

			//reverse_iterator
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			//reverse_iterator
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			void erase( iterator pos )
			{
				erase(pos.node);
			}
			void swap( map& other )
			{
				ft::swap(super_root, other.super_root);
				ft::swap(root, other.root);
				ft::swap(comp, other.comp);
				ft::swap(_alloc, other._alloc);
			}
			size_type count( const Key& key ) const
			{
				return find(key) != end() ? 1 : 0;
			}
			
			key_compare key_comp() const
			{
				return comp;
			}
			value_compare value_comp() const
			{
				return comp;
			}
	};
	


			
}
#endif
