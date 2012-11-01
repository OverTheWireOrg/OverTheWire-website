struct auth {
        unsigned int    token;
        unsigned int    perms;
        unsigned int    timestamp;
};


struct sharea {
        int             sem;
        unsigned int    bitmap;
        struct auth     list[32];
};
