class BSTIterator implements Iterator<Node> {

        Node last = null;

        BSTIterator(Node root) {
            if (root == null) return;
            last = root;
            while (last.left != null)
                last = last.left;
        }

        public boolean hasNext() {
            return last != null;
        }

        public Node next() {
            Node cur = last;
            last = findSuccessor(last);
            return cur;
        }

        private Node findSuccessor(Node root) {
            if (root == null) return null;
            if (root.right != null) {
                Node tmp = root.right;
                while (tmp.left != null) tmp = tmp.left;
                return tmp;
            }
            Node father = root.parent;
            Node child = root;
            while (father != null && father.left != child) {
                child = father;
                father = father.parent;
            }
            return father;
        }
    }