
#ifndef EVENTS_H
#define EVENTS_H

typedef short eventType;
typedef unsigned int uint;

#define NOEVENT '$'

eventType getNextEvent(FILE*);

#endif /* EVENTS_H */

