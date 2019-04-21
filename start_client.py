import subprocess
import argparse
import time

cur_core = 0
nb_cores = 1
server = ""

class client(object):
    def __init__(self, port_num, nb_requests, core, client_port):
        self.port_num    = port_num
	self.client_port = client_port

        self.args = ["taskset"]
        self.args.extend(["-c", str(core)])
        self.args.extend(["./armnn_client"])
        self.args.extend([str(server)])
        self.args.extend([str(port_num)])
        self.args.extend([str(client_port)])
        self.args.extend([str(nb_requests)])
        print self.args
        self.log_file_path, log_file = self.create_log()
        self.p = subprocess.Popen(self.args, stdout=log_file)
        log_file.close

    def stop(self):
        while self.process.poll() is None:
            time.sleep(1)
        self.log_file_path.close()

    def create_log(self):
        file_path = "logs/ab_{}".format(self.client_port)
        f = open(file_path, "w+")
        f.write("ab arguments: {}\n\nSTDOUT:\n".format(str(self.args)))
        f.flush()
        return file_path, f

def increment_core_num(core):
    global cur_core
    p = core + cur_core
    cur_core = (cur_core + 1) % nb_cores
    return p

def start_clients(port_num, nb_requests, nb_clients, client_port):
    client_list=[]
    for _ in range(nb_clients):
        nc = increment_core_num(0)
        client_list.append(client(port_num, nb_requests, nc, client_port))
        if client_port > 0:
            client_port += 1
    return client_list

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", help="server ip address")
    parser.add_argument("-p", help="server pot id");
    parser.add_argument("--nb_requests", help="number of requests to make", type=int)
    parser.add_argument("--nb_clients", help="number of clients", type=int)
    parser.add_argument("--nb_cores", help="number of cores", type=int)
    parser.add_argument("--first_client_port", help="client port num", type=int)
    return parser.parse_args()

if __name__ == '__main__':

    args = parse_args()
    server = args.s
    first_client_port = args.first_client_port if args.first_client_port else 11211
    server_port = args.p if args.p else 8080
    nb_clients = args.nb_clients if args.nb_clients else 1
    nb_requests = args.nb_requests if args.nb_requests else 1
    nb_cores = args.nb_cores if args.nb_cores else 1

    client_list = start_clients(server_port, nb_requests, nb_clients, first_client_port)

#    time.sleep(60)
#    total_result = 0

#    for client in client_list:
#        total_result += float(client.parse_result())

#    print total_result
