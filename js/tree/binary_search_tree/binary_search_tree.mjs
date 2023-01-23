import { BinaryTree } from "../binary_tree/bianry_tree.mjs";

class BinarySearchTree {
    constructor(rootNode = null) {
        this.root = rootNode;
    }

    // 삽입
    insert(data) {
        // 처음 삽입하는 경우
        if (this.root == null) {
            this.root = new BinaryTree(data);
            return;
        }

        let currentNode = this.root;
        let parentNode = null;

        while (currentNode != null) {
            parentNode = currentNode;

            if (currentNode.getData() > data) {
                currentNode = currentNode.getLeftSubTree();
            } else if (currentNode.getData() < data) {
                currentNode = currentNode.getRightSubTree();
            } else {
                return;
            }
        }

        let newNode = new BinaryTree(data);

        if (parentNode.getData() > data) {
            parentNode.setLeftSubTree(newNode);
        } else {
            parentNode.setRightSubTree(newNode);
        }
    }

    // 탐색
    search(targetData) {
        let currentNode = this.root;

        while(currentNode != null) {
            if (currentNode.getData() == targetData) {
                return currentNode;
            } else if (currentNode.getData() > targetData) {
                currentNode = currentNode.getLeftSubTree();
            } else {
                currentNode = currentNode.getRightSubTree();
            }
        }

        return null;
    }

    // 제거
    remove(data) {

    }
}

export {BinarySearchTree};