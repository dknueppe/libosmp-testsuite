FROM ubuntu:18.04

RUN apt update \
	&& apt install -y gcc make valgrind python3

CMD ["/bin/bash"]