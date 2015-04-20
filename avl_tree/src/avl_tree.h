#ifndef AVL_TREE
#define AVL_TREE

typedef struct avl_node_t {
  char              * data;
  struct avl_node_t * child_left;
  struct avl_node_t * child_right;
  size_t height;
} avl_node_t;

typedef struct {
  struct avl_node_t  * head;
  size_t               count;
} avl_tree_t;

avl_tree_t * avl_init( void );
void avl_deinit( avl_tree_t * tree );
void avl_insert( avl_tree_t * tree, char * data );
void avl_delete( avl_tree_t * tree, char * data );
// TODO: Make tree hold values given a key
void * avl_get( avl_tree_t * tree, void * key );
size_t avl_contains( avl_tree_t * tree, char * data );
size_t avl_count( avl_tree_t * tree );
void avl_print( avl_tree_t * tree );

#endif
