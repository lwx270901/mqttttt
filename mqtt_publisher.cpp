#include <stdio.h>
#include <mosquitto.h>

int main(int argc, char *argv[])
{
    struct mosquitto *mosq = NULL;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (mosq == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    mosquitto_connect(mosq, "localhost", 1883, 60);

    mosquitto_publish(mosq, NULL, "test/topic", 13, "Hello, world!", 0, false);

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return 0;
}
