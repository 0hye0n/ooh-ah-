#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE    1024

void ChildRun(int shmid);

int main(int argc, char **argv) {
    int shmId, pid;
    char *ptrShm;

    /* shmget 시스템 콜을 사용하여 공유 메모리를 만들고, shmId를 반환한다. */
    if ((shmId = shmget(IPC_PRIVATE, SHM_SIZE, SHM_R|SHM_W)) < 0) {
        perror("shmget error");
        exit(-1);
    }

    /* shmat 시스템 콜을 사용하여 자신의 프로세스에 공유 메모리를 attach한다. */
    if ((ptrShm = shmat(shmId, 0, 0)) == (void *)-1) {
        perror("shmat error");
        exit(-1);
    }

    ptrShm[0] = 11;
    ptrShm[1] = 22;

    printf("Parent : %d, %d\n", ptrShm[0], ptrShm[1]);

    switch (pid = fork()) {
    case 0:
        ChildRun(shmId);
        return 0;
    case -1:
        perror("fork error");
        exit(-1);
    default:
        break;
    }

    waitpid(pid, NULL, 0);

    printf("Parent : %d, %d\n", ptrShm[0], ptrShm[1]);

    if (shmdt(ptrShm) < 0) {
        perror("shmctl error");
        exit(-1);
    }

    if (shmctl(shmId, IPC_RMID, 0) < 0) {
        perror("shmctl error");
        exit(-1);
    }

    return 0;
}

void ChildRun(int shmid) {
    int shmId;
    char *ptrShm;

    shmId = shmid;

    if ((ptrShm = shmat(shmId, 0, 0)) == (void *)-1) {
        perror("shmat error");
        exit(-1);
    }

    printf("Child  : %d, %d\n", ptrShm[0], ptrShm[1]);
    printf("Child  : Modify value.\n");
    ptrShm[0] = 33;
    ptrShm[1] = 44;

    if (shmdt(ptrShm) < 0) {
        perror("shmctl error");
        exit(-1);
    }
}
[출처] 프로세스간 통신(IPC)|작성자 bycho211