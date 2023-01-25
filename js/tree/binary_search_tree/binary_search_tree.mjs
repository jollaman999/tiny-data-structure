import { BinaryTree } from "../binary_tree/bianry_tree.mjs"

class BinarySearchTree {
    constructor(rootNode = null) {
        this.root = rootNode
    }

    insert(data) {
        if (this.root == null) {
            this.root = new BinaryTree(data);
            return;
        }

        let currentNode = this.root;
        let parentNode = null;

        while (currentNode != null) {
            parentNode = currentNode;

            if (data > currentNode.getData()) {
                currentNode = currentNode.getRightSubTree();
            } else if (data < currentNode.getData()) {
                currentNode = currentNode.getLeftSubTree();
            } else {
                return;
            }
        }

        if (data > parentNode.getData()) {
            parentNode.setRightSubTree(new BinaryTree(data));
        } else {
            parentNode.setLeftSubTree(new BinaryTree(data));
        }
    }

    search(data) {
        let currentNode = this.root;

        while (currentNode != null) {
            if (data > currentNode.getData()) {
                currentNode = currentNode.getRightSubTree();
            } else if (data < currentNode.getData()) {
                currentNode = currentNode.getLeftSubTree();
            } else {
                return currentNode;
            }
        }

        return null;
    }

    remove(data) {
        let currentNode = this.root;
        let parentNode = null;
        let replacingNode = null;
        let replacingNodeParent = null;
        let deletingNode = null;
        let deletingNodeChild = null;
        let fakeParentRootNode = new BinaryTree(0);

        fakeParentRootNode.setRightSubTree(this.root);

        while (currentNode != null) {
            parentNode = currentNode;

            if (data > currentNode.getData()) {
                currentNode = currentNode.getRightSubTree();
            } else if (data < currentNode.getData()) {
                currentNode = currentNode.getLeftSubTree();
            } else {
                deletingNode = currentNode;
                break;
            }
        }

        if (deletingNode == null) {
            return null;
        }

        console.log("target: ", data)

        if (deletingNode.getLeftSubTree() == null && deletingNode.getRightSubTree() == null) {
            if (parentNode.getLeftSubTree() == deletingNode) {
                parentNode.setLeftSubTree(null);
            } else {
                parentNode.setRightSubTree(null);
            }
        } else if (deletingNode.getLeftSubTree() == null || deletingNode.getRightSubTree() == null) {
            if (deletingNode.getLeftSubTree() != null) {
                deletingNodeChild = deletingNode.getLeftSubTree();
            } else {
                deletingNodeChild = deletingNode.getRightSubTree();
            }

            if (parentNode.getLeftSubTree() == deletingNode) {
                parentNode.setLeftSubTree(deletingNodeChild);
            } else {
                parentNode.setRightSubTree(deletingNodeChild);
            }
        } else {
            replacingNode = deletingNode.getLeftSubTree();
            replacingNodeParent = deletingNode;

            while (replacingNode.getRightSubTree() != null) {
                replacingNodeParent = replacingNode;
                replacingNode = replacingNode.getRightSubTree();
            }

            let deletingNodeData = deletingNode.getData();
            deletingNode.setData(replacingNode.getData());

            if (replacingNodeParent.getRightSubTree() == replacingNode) {
                replacingNodeParent.setRightSubTree(replacingNode.getLeftSubTree());
            } else {
                replacingNodeParent.setLeftSubTree(replacingNode.getLeftSubTree());
            }
            
            replacingNode.setData(deletingNodeData);
            deletingNode = replacingNode;
        }

        if(fakeParentRootNode.getRightSubTree() != this.root){
            this.root = fakeParentRootNode.getRightSubTree();
        }

        return deletingNode;
    }
}

export {BinarySearchTree};
