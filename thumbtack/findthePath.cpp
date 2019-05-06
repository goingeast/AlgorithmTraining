#include <iostream>
#include <vector>

using namespace std;

class Node {
	public:
		Node(int val)
		{
			val_ = val;
			left_ = right_ = NULL;
		}
		int val_;
		Node *left_, *right_;
};

class Path {
	public:
		Path()
		{
			sum_ = INT_MIN;
		}
		int sum_;
		vector<Node *> path_;
};

Path MaxSumPath(Node *n, Path &out)
{
	if (!n) {
		return Path();
	}
	Path l = MaxSumPath(n->left_, out);
	Path r = MaxSumPath(n->right_, out);
	int sum = n->val_;
	if (l.sum_ > 0) {
		sum += l.sum_;
	}
	if (r.sum_ > 0) {
		sum += r.sum_;
	}
	if (sum > out.sum_) {
		out.sum_ = sum;
		out.path_.clear();
		if (l.sum_ > 0) {
			out.path_.insert(out.path_.end(), l.path_.begin(), l.path_.end());
		}
		out.path_.push_back(n);
		if (r.sum_ > 0) {
			for (int i = r.path_.size() - 1; i >= 0; --i) {
				out.path_.push_back(r.path_[i]);
			}
		}
	}
	Path p = l.sum_ > r.sum_ ? l : r;
	if (p.sum_ < 0) {
		p = Path();
	}
	p.sum_ = (p.sum_ == INT_MIN) ? n->val_ : p.sum_ + n->val_;
	p.path_.push_back(n);
	return p;
}

Path MaxSumPath2(Node *n, Path &out)
{
	if (!n) {
		return Path();
	}
	Path l = MaxSumPath(n->left_, out);
	Path r = MaxSumPath(n->right_, out);
	int sum = n->val_ + l.sum_ + r.sum_;

	if (sum > out.sum_) {
		out.sum_ = sum;
		out.path_.clear();
		
		out.path_.insert(out.path_.end(), l.path_.begin(), l.path_.end());
		
		out.path_.push_back(n);
		
        for (int i = r.path_.size() - 1; i >= 0; --i) {
            out.path_.push_back(r.path_[i]);
        }
		
	}
	Path p = l.sum_ > r.sum_ ? l : r;
    p.sum_ += n->val_;
	p.path_.push_back(n);
    
	if (p.sum_ < 0) {
		p = Path();
	}
	
	return p;
}

int main()
{
/*
       (1)
       /
    (2)
    / \
  (3) (4) 
  /   /
(6)	(7)
    / \
  (5) (8)
*/
	Node n1(1);
	Node n2(2);
	Node n3(-33);
	Node n4(4);
	Node n5(5);
	Node n6(6);
	Node n7(7);
	Node n8(8);
	n1.left_ = &n2;
	n2.left_ = &n3;
	n2.right_ = &n4;
	n3.left_ = &n6;
	n4.left_ = &n7;
	n7.left_ = &n5;
	n7.right_ = &n8;

	Path path;
	MaxSumPath(&n1, path);
	cout << path.sum_ << ": ";
	for (Node *n : path.path_) {
		cout << n->val_ << "->";
	}
	cout << "\n";
}