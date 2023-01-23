class BinaryTree {
    constructor(data, leftSubTree = null, rightSubTree = null) {
        this.data = data;
        this.leftSubTree = leftSubTree;
        this.rightSubTree = rightSubTree
    }

    // 해당 트리(노드)의 데이터 리턴
    getData() {
        return this.data;
    }

    // 해당 트리(노드)으 ㅣ데이터 설정
    setData(data) {
        this.data = data;
    }

    // 해당 트리(노드)의 왼쪽 서브 트리 리턴
    getLeftSubTree() {
        return this.leftSubTree;
    }

    // 해당 트리(노드)의 오른쪽 서브 트리 리턴
    getRightSubTree() {
        return this.rightSubTree;
    }

    // 해당 트리의 왼쪽 서브트리를 tree로 설정
    setLeftSubTree(tree) {
        this.leftSubTree = tree;
    }

    // 해당 트리의 오른쪽 서브트리를 tree로 설정
    setRightSubTree(tree) {
        this.rightSubTree = tree;
    }

    // 전위순위
    // 루트 노드->왼쪽 자식 노드->오른쪽 자식 노드 순으로 순회한다.
    preOrderTraversal(tree) {
        if (tree == null) return;

        console.log(tree.data);
        this.preOrderTraversal(tree.getLeftSubTree());
        this.preOrderTraversal(tree.getRightSubTree());
    }

    // 중위순위
    // 왼쪽 자식노드->루트 노드->오른쪽 자식 노드 순으로 순회한다.
    inOrderTraversal(tree) {
        if (tree == null) return;

        this.inOrderTraversal(tree.getLeftSubTree());
        console.log(tree.data);
        this.inOrderTraversal(tree.getRightSubTree());
    }

    // 후위순위
    // 왼쪽 자식노드->오른쪽 자식 노드->루트 노드 순으로 순회한다.
    postOrderTraversal(tree) {
        if (tree == null) return;

        this.postOrderTraversal(tree.getLeftSubTree());
        this.postOrderTraversal(tree.getRightSubTree());
        console.log(tree.data);
    }
}

export {BinaryTree};







