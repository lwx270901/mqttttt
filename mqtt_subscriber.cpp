#include <stdio.h>
#include <mosquitto.h>

void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    printf("Received message on topic %s: %.*s\n", message->topic, message->payloadlen, (char *)message->payload);
}

int main(int argc, char *argv[])
{
    struct mosquitto *mosq = NULL;

    mosquitto_lib_init();

    mosq = mosquitto_new(NULL, true, NULL);
    if (mosq == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    mosquitto_message_callback_set(mosq, on_message);

    mosquitto_connect(mosq, "localhost", 1883, 60);
    mosquitto_subscribe(mosq, NULL, "test/topic", 0);

    mosquitto_loop_forever(mosq, -1, 1);

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return 0;
}
