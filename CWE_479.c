//c 479

char *message;
void sh(int dummy) {
syslog(LOG_NOTICE,"%s\n",message);
sleep(10);
exit(0);
}
int main(int argc,char* argv[]) {
...
signal(SIGHUP,sh);
signal(SIGTERM,sh);
sleep(10);
exit(0);
}
If the execution of the first call to the signal handler is suspended after invoking syslog(), and the signal handler is called a second time, the memory allocated by syslog() enters an undefined, and possibly, exploitable state.