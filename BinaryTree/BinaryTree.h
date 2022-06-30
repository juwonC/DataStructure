#pragma once

#include <iostream>
#include <queue>

namespace mytree
{
	struct Node
	{
		int mData;

		Node* mpLeft;
		Node* mpRight;

		Node(int data, Node* left, Node* right)
		{
			mData = data;
			mpLeft = left;
			mpRight = right;
		}
	};
	
	class BinaryTree
	{
	private:
		Node* mpRoot{};

	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* GetRoot() const
		{
			return mpRoot;
		}

		Node* CreateNode(int data)
		{
			return new Node(data, nullptr, nullptr);
		}

		Node* InsertLeft(Node* pParent, int data)
		{
			pParent->mpLeft = CreateNode(data);
			return pParent->mpLeft;
		}

		Node* InsertRight(Node* pParent, int data)
		{
			pParent->mpRight = CreateNode(data);
			return pParent->mpRight;
		}

		void Visit(Node* node)
		{
			std::cout << node->mData << " ";
		}

		void BreadthFirst()
		{
			std::queue<Node*> q;

			q.push(mpRoot);

			while (!q.empty())
			{
				auto pNode = q.front();
				Visit(pNode);
				q.pop();

				if (pNode->mpLeft != nullptr)
				{
					q.push(pNode->mpLeft);
				}

				if (pNode->mpRight != nullptr)
				{
					q.push(pNode->mpRight);
				}
			}
		}
	};
}