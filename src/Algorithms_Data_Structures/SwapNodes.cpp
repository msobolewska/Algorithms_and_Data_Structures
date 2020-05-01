#include <bits/stdc++.h>

using namespace std;

typedef struct Tree{
    int value;
    Tree* left;
    Tree* right;
    int h;
}Tree;

void InorderTraversal(vector<vector<int>>* result, Tree* node, int q, int level){
    if(node->value == -1){
        return;
    }
    if( ( ( node->h )  % q ) == 0 ){
        Tree* temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
    }
    InorderTraversal(result, node->left, q, level);
    (result->at(level)).push_back(node->value);
    InorderTraversal(result, node->right, q, level);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> result;
    if(indexes.size() == 0){
        return result;
    }
    // create a tree
    queue<Tree*> my_queue;
    Tree* my_tree;
    Tree* node = new Tree();
    node->value = 1;
    node->h = 1;

    my_tree = node;

    int max_height = 0;

    for(vector<int> pair_c : indexes){
        Tree* left = new Tree();
        left->value = pair_c.front();
        left-> h = my_tree->h+1;
        my_tree->left = left;

        Tree* right = new Tree();
        right->value = pair_c.back();
        right-> h = my_tree->h+1;
        my_tree->right = right;

        if(pair_c.front() != -1){
            my_queue.push(left);
            if(my_tree->h+1 > max_height){
            max_height = my_tree->h+1;
            }
        }
        if(pair_c.back() != -1){
            my_queue.push(right);
            if(my_tree->h+1 > max_height){
            max_height = my_tree->h+1;
            }
        }
        my_tree = my_queue.front();
        my_queue.pop();
    }

    for(int i = 0; i < queries.size(); i++){
        result.push_back(vector<int>());
        cout << " q: " << queries.at(i) << endl;
        InorderTraversal(&result, node, queries.at(i), i);
    }

    delete node;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
