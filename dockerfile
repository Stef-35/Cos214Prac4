FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    g++ \
    make \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY *.cpp *.h Makefile ./

RUN useradd -m -u 1000 appuser && \
    chown -R appuser:appuser /app

USER appuser

RUN make

CMD ["./taskforge"]