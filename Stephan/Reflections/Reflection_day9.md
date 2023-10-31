# Reflection Day 7

We started the day with the topic of security and encryption. Through the slides we had certain tasks to research questions abouot the topics.

## Tasks

### Which security vulnerabilities did you encounter in your IoT systems?
- our passwords are hard coded
- No certification
- No ssl or tsl
- If the gyroscope was stolen anyone with the gyroscope could open the door
- always use the same port

### Which measure can be taken to close the vulnerabilities?
-changing the port number regularly
-Start using ssl/tls
-Not hard code passwords and start to create different measures to secure them.

### what is a cipher suite?
A cipher suite, in the context of encryption and security, refers to a combination of encryption algorithms and cryptographic protocols used to secure network communication. These suites are commonly used in various security protocols like SSL/TLS (Secure Sockets Layer/Transport Layer Security) to ensure the confidentiality, integrity, and authenticity of data transmitted over a network.

- Key Exchange Algorithm
- Authentication Algorithm
- Bulk Encryption Algorithm
- Message Authentication Code (MAC) Algorithm
- Hash Function
- Protocol Version

### What is a chain of trust?
Is a hierarchical sequence of certificates and public keys used to establish and verify the authenticity and trustworthiness of digital identities, such as websites and online services

### What is the root certificate authority (CA)?
The root certificate authority (CA) is the highest level of trust in a Public Key Infrastructure (PKI) hierarchy. It is a fundamental component of the digital certificate system used to establish the trust and authenticity of digital identities, websites, and online services

### What is an intermediate certificate authority (ICA)?
Certificate Authority (CA) in a Public Key Infrastructure (PKI) hierarchy that falls between the root certificate authority (CA) and end-entity certificates. The role of an intermediate CA is to issue certificates to specific entities, such as websites, email servers, or individuals, while being linked to and trusted by the root CA.

### What is an end-user certificate?
An end-user certificate, in the context of Public Key Infrastructure (PKI) and digital security, refers to a digital certificate issued to an individual, device, or entity for the purpose of enabling secure communications, authentication, and encryption. These certificates are used by end entities (users or devices) to prove their identity, establish secure connections, and protect data integrity and confidentiality. End-user certificates are a fundamental component of various security protocols and applications, including SSL/TLS for securing web communications, email encryption, code signing, and more.

### What topological structure of certificates is created by a CA?
hierarchical topological structure of digital certificates in a Public Key Infrastructure (PKI) system

### What is the depth of a certificate?
The depth of a certificate, often referred to as the "certificate depth" or "certification path depth," is a measure of how many certificates are in the chain of trust that must be traversed when verifying the authenticity and integrity of a particular end-entity certificate within a Public Key Infrastructure (PKI)

### What ist the name of an other prominent representative of a chain of trust?
Certificate Revocation List (CRL). Pretty-good-privacy (PGP).

### How do root of trust and web of trust differ?

**Root of trust is:**
- centralized
- PKI-based
- Used in ssl/tsl

**Web trust is:**
- Decentralized
- P2P based
- Used in email encryption

### Which one is more secure?
The security of both models depends on the proper implementation and management of trust. In practice, the security of a system using either model is influenced by factors such as policy, procedures, auditing, and the threat landscape.

### How are Diffie-Hellman key exchange and SSL/TLS related?
In SSL/TLS, one of the initial steps in establishing a secure connection between a client and a server is to negotiate a shared secret key for encryption and decryption. This key exchange phase is essential to ensure the confidentiality and integrity of data transmitted during the session. Diffie-Hellman key exchange is one of the methods used to accomplish this. The Diffie-Hellman key exchange typically takes place during the SSL/TLS handshake phase. During this handshake, the client and server agree on the cryptographic parameters, exchange public keys, and derive the shared secret key. This key is then used for secure communication throughout the session.

### How are RSA key exchange and SSL/TLS related?
RSA key exchange is a method used in SSL/TLS to securely negotiate a shared secret key between a client and a server. It's part of the SSL/TLS handshake process and enables encryption and secure communication. In RSA key exchange, the server's public key is used by the client to encrypt a premaster secret, which is then decrypted by the server using its private key. This shared secret is used for data encryption during the SSL/TLS session, ensuring confidentiality and data integrity.

## Tasks about OpenWRT (Individual)

### How one can access the WEB interface of OpenWRT
Open a new browser tab and then type in the IP address of the router. In our case 192.168.12.254
This then promts for the password. The password should be the same as the wifi password. The interface then opens and have been accessed.

### How one can discover the symbolic host name of the lan interface address.

If you go into the network tab in the interface then navigate to interfaces. The symbolic host name is the name corresponding to the lan. In our case it was "br-lan".

### How one can ssh into the router using the IP address or the symbolic host name and execute shell commands.

This can be done with a Cmder. The command prompt on most computers will be able to accomplish this. Into a command line you only need to type ssh root@ipaddress then enter.

# How one can sftp into the router and upload/download files to and from it.

### How one can install new packages on the router using either

Web Interface:

opkg command line utility:

# Where are the remote package repositories configured?

# Group Tasks

This task has been done by Vincent:
For the last challenge of the day, we are going the reconfigure the router as a MQTTbroker.

The challenge is as followed:

- Download the key
- Add the key to the Router
- Add the package to the customfeeds.conf
- Install mqttbroker

So as first we needed to get the key. The key is located on a website that was provided by the teacher. The key we used is as followed:

- untrusted comment: Local build key
RWR2RtSIIMm9nRorcS+OJzAMymAjjdBtXr4MpAbbqQuHsDzszEt1pkK4

This key needed to added to the router. To get access to the router I used the following command: 

- ssh root@192.168.12.254 
![SSH openWrt](../Photos/SSH_openwrt.png)

After I was connected to the Router via SSH, I located the correct file place which is:

- /etc/opkg/keys

This is the location were all the trusted keys are located. 

Because I really dispice Vim I did the following to install nano

- opkg update
- opkg install nano

So with nano now available for me, I created a new file named:

- 7646d48820c9bd9d

In this file I pasted the untrusted comment.

After I did that, I added a https, so I would get the correct package, so I could install the MQTT broker. 

To change the file I did the following command:

- Nano /etc/opkg/customfeeds.conf

The file looks as followed:

![Customfeeds.conf](../Photos/Customfeeds.conf.png)

After I added the line and saved the document. I did another update with the command:

- opkg update

After that MQTTbroker was available to download. To install the MQTTbroker I did the with the following command:

- opkg install mqttbroker

To check if the broker works I did the following command:

- ps | grep mqtt:
![Ps | Grep mqtt](../Photos/ps_Grep.png)

So now we know that MQTT broker works and is running. So I have succesfully installed MQTTbroker on the router.