#ifndef D08DC2F2_EEE3_4E82_A17A_E058AFC647FB
#define D08DC2F2_EEE3_4E82_A17A_E058AFC647FB

// Defines the HashTable item.
typedef struct hash_table_item
{
    uint32_t* key;
    char* value;
} hash_table_item;

hash_table_item* createItem(uint32_t* key, char* value);


#endif /* D08DC2F2_EEE3_4E82_A17A_E058AFC647FB */
