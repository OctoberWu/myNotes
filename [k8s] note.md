keywords: k8s

---
### quick note:
> 需要 Pod 來作為基本單位的原因是，如果每個 Container 都作為 K8S 的最小單位，那麼管理網路會變得非常的困難。以 Pod 來區隔，同一個 Pod 裡面的 Container 能夠在本地端互相的連線，只有需要提供給外部呼叫的 API 才需要暴露出來。

#### Install and Use Kubernetes on Ubuntu 20.04
* container orchestration 
* `master node` and `worker node`

#### installation steps:
##### step 1: Install Kubernetes
```sh 
# get the package 
sudo apt install apt-transport-https curl

# add the Kubernetes signing key to both nodes by executing the command:
curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add

# add the Kubernetes repository as a package source on both nodes using the following command:
echo "deb https://apt.kubernetes.io/ kubernetes-xenial main" >> ~/kubernetes.list
sudo mv ~/kubernetes.list /etc/apt/sources.list.d

# update the nodes
sudo apt update 
```
##### Install Kubernetes tools
Once the update completes, we will install Kubernetes. This involves installing the various tools that make up Kubernetes: kubeadm, kubelet, kubectl, and kubernetes-cni. These tools are installed on both nodes. We define each tool below:

* kubelet – an agent that runs on each node and handles communication with the master node to initiate workloads in the container runtime. Enter the following command to install kubelet:
```sh
sudo apt install kubelet
```

* kubeadm – part of the Kubernetes project and helps initialize a Kubernetes cluster. Enter the following command to install the kubeadm:
```sh
sudo apt install kubeadm
```

* kubectl – the Kubernetes command-line tool that allows you to run commands inside the Kubernetes clusters. Execute the following command to install kubectl:
```sh
sudo apt install kubectl
```

* kubernetes-cni – enables networking within the containers ensuring containers can communicate and exchange data. Execute the following command to install:
```sh
sudo apt-get install -y kubernetes-cni
```

Optionally, you can install all four in a single command:
```sh
sudo apt-get install -y kubelet kubeadm kubectl kubernetes-cni
```

##### step 2: 


quick problem records
=====================
```sh
The connection to the server localhost:8080 was refused - did you specify the right host or port?
```
- 推論，kubernetes的server 未設置