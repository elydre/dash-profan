#ifndef SYS_TIME_H
#define SYS_TIME_H

struct timeval {
  long tv_sec;  /* secondes */
  long tv_usec; /* microsecondes */
};

struct rusage {
  struct timeval ru_utime; /* Temps utilisateur écoulé         */
  struct timeval ru_stime; /* Temps système écoulé             */
  long  ru_maxrss;         /* Taille résidente maximale        */
  long  ru_ixrss;          /* Taille de mémoire partagée       */
  long  ru_idrss;          /* Taille des données non partagées */
  long  ru_isrss;          /* Taille de pile                   */
  long  ru_minflt;         /* Demandes de pages                */
  long  ru_majflt;         /* Nombre de fautes de pages        */
  long  ru_nswap;          /* Nombre de swaps                  */
  long  ru_inblock;        /* Nombre de lectures de blocs      */
  long  ru_oublock;        /* Nombre d'écritures de blocs      */
  long  ru_msgsnd;         /* Nombre de messages émis          */
  long  ru_msgrcv;         /* Nombre de messages reçus         */
  long  ru_nsignals;       /* Nombre de signaux reçus          */
  long  ru_nvcsw;          /* Chgmnts de contexte volontaires  */
  long  ru_nivcsw;         /* Chgmnts de contexte involontaires*/
};

#endif // SYS_TIME_H
