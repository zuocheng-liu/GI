#include <inttypes.h>
namespace GI {
typedef struct uwsgi_packet_header {
    uint8_t modifier1;
    uint16_t datasize;
    uint8_t modifier2;
} uwsgi_packet_header;

typedef struct uwsgi_var {
    uint16_t key_size;
    uint8_t *key;
    uint16_t val_size;
    uint8_t *val;
} uwsgi_var;

} // end namespace GI
