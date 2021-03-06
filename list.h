#pragma once

#define list_add(item, list) do { \
    item->prev = NULL; \
    item->next = list; \
    if (list != NULL) list->prev = item; \
    list = item; \
} while (0)

#define list_rm(item, list) do { \
    if (item->prev != NULL) item->prev->next = item->next; \
    if (item->next != NULL) item->next->prev = item->prev; \
    if (list == item) list = item->next; \
    item->prev = item->next = NULL; \
} while (0)

struct wait_queue_entry;

typedef int (*wait_queue_func_t)(struct wait_queue_entry *wq_entry, unsigned mode, int flags, void *key);

typedef struct wait_queue_entry {
    unsigned int        flags;
    void                *private;
    wait_queue_func_t   func;
    struct wait_queue_entry *prev, *next;
} wait_queue_entry_t;