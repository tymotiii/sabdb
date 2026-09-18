#include "mongoose.h"
#include <unistd.h>
#define MAX_TABLES 15
#define MAX_ENTRIES 15
#define MAX_KVALS 5

struct kval {
    char key[50];
    char val[256];
};

struct entry {
    struct kval kvals[MAX_KVALS];
    char name[256];

};

struct table {
    struct entry entries[MAX_ENTRIES];
    char name[256];
};


struct sabdb {
    struct table tables[MAX_TABLES];
};

static void handler(struct mg_connection *c, int ev, void *ev_data) {
    if (ev != MG_EV_HTTP_MSG) {
        return;
    }

    struct mg_http_message *hm = (struct mg_http_message *) ev_data;

    if (mg_match(hm->uri, mg_str("/query"), NULL)) {
        mg_http_reply(c, 200, "Content-Type: text/plain\r\n", "Hello from db /query");
    }
}

int main(void) {
    struct mg_mgr mgr;
    struct sabdb db;


    mg_mgr_init(&mgr);

    mg_http_listen(&mgr, "htpp://0.0.0.0:9165", handler, NULL);

    for (;;) {
        mg_mgr_poll(&mgr, 1000);
    }

    mg_mgr_free(&mgr);

}
