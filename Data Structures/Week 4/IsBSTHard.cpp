#include<bits/stdc++.h>

using namespace std;

using Type = long long;
constexpr Type INF = numeric_limits< Type >::max();

struct Tree_node;
using H_Tree_node = shared_ptr< Tree_node >;
struct Tree_node {
    Type val, min, max;
    H_Tree_node left, right;
    Tree_node( Type val, Type min=-INF, Type max=INF )
        : val{ val }, min{ min }, max{ max }, left{ nullptr }, right{ nullptr } {}
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

namespace failed_case_40_of_95_unknown_signal_11 { 
    class Solution {
    public:
        bool isBST( H_Tree_node root ){
            auto ok{ true };
            if( root )
                go( root, ok );
            return ok;
        }
    private:
        using MinMax = pair< Type,Type >;
        MinMax go( H_Tree_node root, bool& ok ){
            if( ! ok )
                return{ 0,0 };
            if( ! root->left && ! root->right )
                return{ root->val, root->val };
            auto[ L1, L2 ] = root->left?  go( root->left,  ok ) : make_pair( root->val, root->val );
            auto[ R1, R2 ] = root->right? go( root->right, ok ) : make_pair( root->val, root->val );
            if( root->left && max( L1, L2 ) >= root->val )
                ok = false;
            if( root->right && root->val > min( R1, R2 ) )
                ok = false;
            return{  max({ root->val, L1, L2, R1, R2 }),
                        min({ root->val, L1, L2, R1, R2 })  };
        }
    };
}

namespace failed_case_44_of_95_unknown_signal_11 { 
    class Solution {
    public:
        bool isBST( H_Tree_node root, Type min=numeric_limits< Type >::min(), Type max=numeric_limits< Type >::max() ){
            return go( root, min, max );
        }
    private:
        bool go( H_Tree_node root, Type min, Type max ){
            if( ! root )
                return true;
            if( min > root->val || root->val >= max )
                return false;
            return go( root->left, min, root->val ) &&
                    go( root->right, root->val, max );
        }
    };
} 

class Solution {
public:
    bool isBST( H_Tree_node node, Collection stack={} ){ 
        if( node )
            stack.push_back( node );
        while( ! stack.empty() ){
            node = stack.back(), stack.pop_back();
            if( node->min > node->val || node->val >= node->max )
                return false;
            if( node->right ){ 
                node->right->min = node->val;
                node->right->max = node->max;
                stack.push_back( node->right );
            }
            if( node->left ){
                node->left->min = node->min;
                node->left->max = node->val;
                stack.push_back( node->left );
            }
        }
        return true;
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