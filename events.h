
#ifndef EVENTS_H
#define EVENTS_H

typedef short eventType;

#define NOEVENT '$'

eventType getNextEvent(FILE*);

#endif /* EVENTS_H */

