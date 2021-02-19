#include <time.h>
#include <stdlib.h>

int main()
{
	long int ttime;
	ttime = time (NULL);
	pid_t pid;
	system("curl https://mp3party.net/music/8451736> a.mp3");

	pid = fork();
	if (pid == 0)
		while(1)
			system("osascript -e 'set volume 7' ; pmset displaysleepnow");
	else
	{
		system("afplay a.mp3 &");
		while (time (NULL) - ttime < 30)
		{}
		kill(pid, SIGKILL);
		system("pkill -9 afplay");
		exit(0);
	}
}
