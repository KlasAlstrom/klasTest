#ifndef ROUTER_H
#define	ROUTER_H
#include <stdint.h>

class Router {
public:
   // Application to router interface
   virtual void put_message(const uint32_t msgId, void* msg) = 0;  
   virtual void make_message_local(const uint32_t msgId, bool local) = 0;
   virtual bool subscribe(const uint32_t msgId, void (*callback)(void*, uint32_t, void*), void *subscriber) = 0;
   virtual bool unsubscribe(const uint32_t msgId, void (*callback)(void*, uint32_t, void*), void *subscriber) = 0;
  
   // Router to router interface
   virtual void route_message(Router* sender, const uint32_t msgId, void* msg) = 0;
   virtual void subscribeByRouter(const bool add, const uint32_t msgId, Router* subscriber) = 0;
   virtual void connect(Router* neighbour) = 0;

   // Observer interface
   virtual char* getName(void) = 0;
   virtual Router** getConnectedRouters(void) = 0;
   // virtual getLocalSubscribedMessages(void) = 0;
   // virtual getExternalSubscribedMessages(void) = 0;
   // virtual getLocalMessages(void) = 0;
   
};


#endif	/* ROUTER_H */

