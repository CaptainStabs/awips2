C MODULE AXIS18
C-----------------------------------------------------------------------
C   THIS ROUTINE IS CALLED BY THE EXECUTION ROUTINE
C   OF THE PLOT-TS OPERATION. IT DRAWS THE AXIS FOR THE
C   PLOT.
C
C   THIS ROUTINE WAS INITIALLY PROGRAMMED BY
C   GERALD N. DAY - HRL   MAY 1980
C
C   ARGUMENTS -
C
C     PO - P ARRAY (INPUT)
C     LZERO - PLOT POSITIONS OF THE X AXIS FOR EACH PLOT (OUTPUT)
C     LTENS - PLOT POSITIONS TO MARK THE Y AXIS (THE Y AXIS IS
C             MARKED EVERY TEN COLUMNS STARTING AT THE X AXIS OF
C             EACH PLOT (OUTPUT)
C     NTENS - THE TOTAL NUMBER OF PLOT POSITIONS USED TO MARK THE
C             Y AXIS (OUTPUT)
C     IPLOT - PLOT NUMBERS (1,2,,ETC.) (WORK)
C     FMT - VARIABLE FORMAT STATEMENT FOR DRAWING THE AXIS (WORK)
C-----------------------------------------------------------------------
      SUBROUTINE AXIS18 (PO,LZERO,LTENS,NTENS,IPLOT,FMT)
C
      DIMENSION PO(*),LZERO(*),LTENS(12),IPLOT(*),ORD(12)
      CHARACTER*4  FVAL(31),FMT(70)
C
      COMMON/IONUM/IN,IPR,IPU
      COMMON/FENGMT/METRIC
      COMMON/FDBUG/IODBUG,ITRACE,IDBALL,NDEBUG,IDEBUG(20)
C
C    ================================= RCS keyword statements ==========
      CHARACTER*68     RCSKW1,RCSKW2
      DATA             RCSKW1,RCSKW2 /                                 '
     .$Source: /fs/hseb/ob72/rfc/ofs/src/fcst_plotts/RCS/axis18.f,v $
     . $',                                                             '
     .$Id: axis18.f,v 1.2 2000/12/19 15:05:31 dws Exp $
     . $' /
C    ===================================================================
C
      DATA PTYPE/4HARIT/
      DATA FVAL/4H  ,1,4H  ,2,4H  ,3,4H  ,4,4H  ,5,4H  ,6,4H  ,7,
     1 4H  ,8,4H  ,9,4H ,10,4H ,11,4H ,12,4H6   ,4H5   ,4H4   ,
     2 4H3   ,4H2   ,4H1   ,4H0   ,4HX   ,4H  I4,4H,4HP,4HLOT,,
     3 4H,4HD,4HAY  ,4H 2HH,4HR   ,4H(1H0,4H)   ,4HF10.,4H    /
      IF(ITRACE.GE.1) WRITE(IPR,900)
C
C   INITIALIZE FORMAT AS BLANKS
C
      DO 10 I=1,70
      FMT(I)=FVAL(31)
   10 CONTINUE
      IDT=PO(11)
      FMT(1)=FVAL(28)
      IF(IDT.NE.24) GO TO 20
C
C   SET UP DAY LABEL
C
      FMT(2)=FVAL(3)
      FMT(3)=FVAL(20)
      FMT(4)=FVAL(24)
      FMT(5)=FVAL(25)
      ITFMT=5
      GO TO 30
C
C   SET UP DAY/HR LABEL
C
   20 FMT(2)=FVAL(1)
      FMT(3)=FVAL(20)
      FMT(4)=FVAL(24)
      FMT(5)=FVAL(25)
      FMT(6)=FVAL(26)
      FMT(7)=FVAL(27)
      ITFMT=7
   30 FMT(ITFMT+1)=FVAL(5)
      FMT(ITFMT+2)=FVAL(20)
      ITFMT=ITFMT+2
C
      NPLOTS=PO(8)
C
      DO 100 I=1,NPLOTS
      IPO=11+9*(I-1)
C
C   SKIP THE FIRST HALF OF THE POINTS FOR THE PLOT
C
      NPTS=PO(IPO+2)
      ISKIP=NPTS/2-4
      ISKIP0=ISKIP/10
      IF(ISKIP0.EQ.0) GO TO 60
      DO 50 J=1,ISKIP0
      K=1+2*(J-1)
      FMT(ITFMT+K)=FVAL(10)
      FMT(ITFMT+K+1)=FVAL(20)
   50 CONTINUE
      ITFMT=ITFMT+2*ISKIP0
   60 ISKIP1=ISKIP-ISKIP0*10
      IF(ISKIP1.EQ.0) GO TO 70
      FMT(ITFMT+1)=FVAL(ISKIP1)
      FMT(ITFMT+2)=FVAL(20)
      ITFMT=ITFMT+2
C
C   SET UP PLOT LABEL
C
   70 FMT(ITFMT+1)=FVAL(22)
      FMT(ITFMT+2)=FVAL(23)
      FMT(ITFMT+3)=FVAL(21)
      ITFMT=ITFMT+3
C
C   SKIP THE REMAINING POINTS FOR THE PLOT
C
      LSKIP=NPTS-ISKIP-8
      LSKIP0=LSKIP/10
      IF(LSKIP.EQ.0) GO TO 90
      DO 80 J=1,LSKIP0
      K=1+2*(J-1)
      FMT(ITFMT+K)=FVAL(10)
      FMT(ITFMT+K+1)=FVAL(20)
   80 CONTINUE
      ITFMT=ITFMT+2*LSKIP0
   90 LSKIP1=LSKIP-LSKIP0*10
      IF(LSKIP1.EQ.0) GO TO 100
      FMT(ITFMT+1)=FVAL(LSKIP1)
      FMT(ITFMT+2)=FVAL(20)
      ITFMT=ITFMT+2
  100 CONTINUE
      FMT(ITFMT+1)=FVAL(29)
      DO 110 I=1,NPLOTS
      IPLOT(I)=I
  110 CONTINUE
      WRITE(IPR,FMT) (IPLOT(I),I=1,NPLOTS)
C   INITIALIZE FORMAT AS BLANKS
C
      DO 120 I=1,70
      FMT(I)=FVAL(31)
  120 CONTINUE
      FMT(1)=FVAL(28)
      FMT(2)=FVAL(4)
      FMT(3)=FVAL(20)
      ITFMT=3
      NTORD=0
      NTENS=0
      LZERO(1)=1
      DO 200 I=1,NPLOTS
      IPO=11+9*(I-1)
      TYPE=PO(IPO+1)
      NPTS=PO(IPO+2)
C
C   CALCULATE THE NUMBER OF LABELED ORDINATES.
C
      NORD=NPTS/10
      PMIN=PO(IPO+3)
      PMAX=PO(IPO+4)
      IF(METRIC.EQ.1) GO TO 125
C
C   CONVERT THE MAX/MIN ORDINATES TO ENGLISH UNITS
C
      CFACT=PO(IPO+8)
      CONST=PO(IPO+9)
      PMIN=PMIN*CFACT+CONST
      PMAX=PMAX*CFACT+CONST
  125 IF(I.EQ.NPLOTS) GO TO 130
C
C   CALCULATE THE LOCATION OF EACH X AXIS
C
      LZERO(I+1)=LZERO(I)+NPTS
C
C   DETERMINE FORMAT TO OUTPUT LABELS
C
  130 FMT(ITFMT+1)=FVAL(NORD)
      FMT(ITFMT+2)=FVAL(30)
      FMT(ITFMT+3)=FVAL(19)
      IF(PMAX.LT.10000.) FMT(ITFMT+3)=FVAL(18)
      IF(PMAX.LT.1000.) FMT(ITFMT+3)=FVAL(17)
      IF(PMAX.LT.100.) FMT(ITFMT+3)=FVAL(16)
      IF(PMAX.LT.10.) FMT(ITFMT+3)=FVAL(15)
      IF(PMAX.LT.1.) FMT(ITFMT+3)=FVAL(14)
      IF(PMAX.LT..1) FMT(ITFMT+3)=FVAL(13)
      ITFMT=ITFMT+3
      IF(TYPE.EQ.PTYPE) GO TO 135
C
C   CALCULATE THE LOGARITHMS OF THE MAX/MIN
C   ORDINATES FOR THE LOG PLOTS.
C
      PMIN=ALOG10(PMIN)
      PMAX=ALOG10(PMAX)
  135 PTS=NPTS
      DELTA=(PMAX-PMIN)*10./PTS
      DO 140 J=1,NORD
C
C   CALCULATE EACH ORDINATE
      ORD(NTORD+J)=PMIN+(J-1)*DELTA
      IF(TYPE.NE.PTYPE) ORD(NTORD+J)=10**(ORD(NTORD+J))
C
C   CALCULATE THE LOCATIONS TO MARK THE Y AXIS.
C
      NTENS=NTENS+1
      LTENS(NTENS)=LZERO(I)+J*10
  140 CONTINUE
C
C   SKIP THE REMAINING POINTS OF THE PLOT.
C
      ISKIP=NPTS-10*NORD
      IF(ISKIP.EQ.0) GO TO 190
      FMT(ITFMT+1)=FVAL(ISKIP)
      FMT(ITFMT+2)=FVAL(20)
      ITFMT=ITFMT+2
  190 NTORD=NTORD+NORD
  200 CONTINUE
C
      FMT(ITFMT+1)=FVAL(29)
      WRITE(IPR,FMT) (ORD(I),I=1,NTORD)
      IF(ITRACE.GE.1) WRITE(IODBUG,910)
      RETURN
  900 FORMAT(1H0,17H** AXIS18 ENTERED)
  910 FORMAT(1H0,16H** AXIS18 EXITED)
      END
