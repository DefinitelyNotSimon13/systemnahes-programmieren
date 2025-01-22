FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    qemu-system-arm \
    build-essential \
    gcc-arm-none-eabi \
    gdb-multiarch \
    cmake

WORKDIR /app

COPY . /app

# Configure
RUN cmake --preset arm-cortex-m0-unix

# Build
RUN cmake --build --preset arm-cortex-m0-unix

# Output dir if not exists
RUN mkdir -p output

# container needs to be run with -p 1234:1234, don't think this does really
# anything, more of a hint
EXPOSE 1234
