/*****************************************************************************
 * $Source$
 * $Author$
 * $Date$
 * $Revision$
 *****************************************************************************/

#ifndef _AMPI_H
#define _AMPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* MPI prototypes and #defines here */

// these values have to match values in ampif.h

#define AMPI_DOUBLE 0
#define AMPI_INT 1
#define AMPI_REAL 2
#define AMPI_COMPLEX 3
#define AMPI_LOGICAL 4
#define AMPI_CHARACTER 5
#define AMPI_BYTE 6
#define AMPI_PACKED 7

#define AMPI_COMM_WORLD 0
#define AMPI_ANY_SOURCE (-1)

#define AMPI_MAX 1
#define AMPI_MIN 2
#define AMPI_SUM 3
#define AMPI_PROD 4

typedef int AMPI_Comm;
typedef int AMPI_Datatype;
typedef int AMPI_Op;
typedef int AMPI_Request;
typedef struct {
  int one, two, three;
} AMPI_Status;

int AMPI_Init(int *argc, char*** argv);
int AMPI_Comm_rank(AMPI_Comm comm, int *rank);
int AMPI_Comm_size(AMPI_Comm comm, int *size);
int AMPI_Finalize(void);
int AMPI_Send(void *msg, int count, AMPI_Datatype type, int dest,
             int tag, AMPI_Comm comm);
int AMPI_Recv(void *msg, int count, int type, int src, int tag,
             AMPI_Comm comm, AMPI_Status *status);
int AMPI_Sendrecv(void *sbuf, int scount, int stype, int dest,
                 int stag, void *rbuf, int rcount, int rtype,
                 int src, int rtag, AMPI_Comm comm, AMPI_Status *sts);
int AMPI_Barrier(AMPI_Comm comm);
int AMPI_Bcast(void *buf, int count, int type, int root,
              AMPI_Comm comm);
int AMPI_Reduce(void *inbuf, void *outbuf, int count, int type,
               AMPI_Op op, int root, AMPI_Comm comm);
int AMPI_Allreduce(void *inbuf, void *outbuf, int count, int type,
                  AMPI_Op op, AMPI_Comm comm);
double AMPI_Wtime(void);
int AMPI_Start(AMPI_Request *reqnum);
int AMPI_Waitall(int count, AMPI_Request *request, AMPI_Status *sts);
int AMPI_Recv_init(void *buf, int count, int type, int src, int tag,
                  AMPI_Comm comm, AMPI_Request *req);
int AMPI_Send_init(void *buf, int count, int type, int dest, int tag,
                  AMPI_Comm comm, AMPI_Request *req);
int AMPI_Type_contiguous(int count, AMPI_Datatype oldtype, AMPI_Datatype *newtype);
int AMPI_Type_commit(AMPI_Datatype *datatype);
int AMPI_Type_free(AMPI_Datatype *datatype);
int AMPI_Isend(void *buf, int count, AMPI_Datatype datatype, int dest, 
              int tag, AMPI_Comm comm, AMPI_Request *request);
int AMPI_Irecv(void *buf, int count, AMPI_Datatype datatype, int src, 
              int tag, AMPI_Comm comm, AMPI_Request *request);
int AMPI_Allgatherv(void *sendbuf, int sendcount, AMPI_Datatype sendtype, 
                   void *recvbuf, int *recvcounts, int *displs, 
                   AMPI_Datatype recvtype, AMPI_Comm comm) ;
int AMPI_Allgather(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
                  void *recvbuf, int recvcount, AMPI_Datatype recvtype,
                  AMPI_Comm comm);
int AMPI_Gatherv(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
                void *recvbuf, int *recvcounts, int *displs,
                AMPI_Datatype recvtype, int root, AMPI_Comm comm);
int AMPI_Gather(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
               void *recvbuf, int recvcount, AMPI_Datatype recvtype, 
               int root, AMPI_Comm comm);
int AMPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                  AMPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                  int *rdispls, AMPI_Datatype recvtype, AMPI_Comm comm);
int AMPI_Alltoall(void *sendbuf, int sendcount, AMPI_Datatype sendtype, 
                 void *recvbuf, int recvcount, AMPI_Datatype recvtype, 
                 AMPI_Comm comm);
#ifdef __cplusplus
}
#endif

#endif
