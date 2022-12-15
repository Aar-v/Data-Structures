#include <bits/stdc++.h>

using namespace std;

struct Tree_node;
using H_Tree_node = shared_ptr< Tree_node >;
struct Tree_node {
    int val;
    H_Tree_node left, right;
    Tree_node( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
    friend ostream& operator<<( ostream& os, const H_Tree_node& node ){
        if( node )
            os << node->val;
        return os;
    }
};
bool operator<( const H_Tree_node& lhs, const H_Tree_node& rhs ){
    return lhs->val < rhs->val;
}
using Collection = vector< H_Tree_node >;

class Solution {
public:
    bool isBST( H_Tree_node root, Collection inorder={} ){
        go( root, inorder );
        return is_sorted( inorder.begin(), inorder.end() );
    }
private:
    void go( H_Tree_node root, Collection& inorder ){
        if( ! root )
            return;
        go( root->left, inorder );
        inorder.push_back( root );
        go( root->right, inorder );
    }
};

int main() {
    string line;
    auto N{ 0 }; {
        getline( cin, line );
        istringstream is{ line };
        is >> N;
    }
    Collection A;
    generate_n( back_inserter( A ), N, [](){ return make_shared< Tree_node >( 0 ); });
    for( auto i{ 0 }; i < N && getline( cin, line ); ++i ){
        istringstream parser{ line };
        auto val{ 0 }, L{ 0 }, R{ 0 };
        parser >> val >> L >> R;
        A[ i ]->val = val;
        A[ i ]->left =  ( -1 < L )? A[ L ] : nullptr;
        A[ i ]->right = ( -1 < R )? A[ R ] : nullptr;
    }
    auto ok = A.empty() || Solution().isBST( A[ 0 ] );
    cout << ( ok? "CORRECT" : "INCORRECT" ) << endl;
    return 0;
}