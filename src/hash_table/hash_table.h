#ifndef D08DC2F2_EEE3_4E82_A17A_E058AFC647FB
#define D08DC2F2_EEE3_4E82_A17A_E058AFC647FB

// Defines the HashTable item.
typedef struct hash_table_item
{
    uint32_t* key;
    char* value;
} hash_table_item;

typedef struct hash_table
{
    // Contains an array of pointers to items.
    hash_table_item** items;
    int size;
    int count;
} hash_table;

/**
 * @brief Create a Item object
 * 
 * @param key 
 * @param value 
 * @return hash_table_item* 
 */
hash_table_item* createItem(uint32_t key, char value);

/**
 * @brief Create a table object
 * 
 * @param size 
 * @return hash_table* 
 */
hash_table* createTable(int size);

/**
 * @brief 
 * 
 * @param table 
 */
void printTable(hash_table* table);

/**
 * @brief 
 * 
 * @param table 
 * @param key 
 * @param value 
 */
void insertItem(hash_table* table, uint32_t key, char value);

/**
 * @brief 
 * 
 * @param table 
 * @param key 
 * @return char* 
 */
char* searchItem(hash_table* table, uint32_t key);

/**
 * @brief 
 * 
 * @param table 
 * @param key 
 */
void deleteItem(hash_table* table, uint32_t key);


#endif /* D08DC2F2_EEE3_4E82_A17A_E058AFC647FB */
