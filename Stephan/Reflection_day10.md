### Reflection Day 10

## Tasks (Individually)

# How to request a full "template" command line for mqttbroker?

By using the command "mqttbroker --commandline-ful" it will print a template command line showing all options and exit.

# How to retrieve the current configuration of mqttbroker?

By using the command "mqttbroker --commandline-configuration" it will print a template command line showing all required and configured options and exit.

# How to write current configuration to a config file?

mqttbroker -w

# How many server instances (services) does the mqttbroker offer?

5:
  legacyin
       Configuration for server instance 'legacyin'
  tlsin
       Configuration for server instance 'tlsin'
  legacyun
       Configuration for server instance 'legacyun'
  mqtttlswebview
       Configuration for server instance 'mqtttlswebview'
  mqttlegacywebview
       Configuration for server instance 'mqttlegacywebview'

# Via which protocol are the individual instances accessible?

Configuration of SSL/TLS behaviour for instance

# Do all server instances offer the same configuration sections (cathegories)?

No

# Which section of the instances providing encrypted communication, provides the configuration option for SSL/TLS?

Configuration of SSL/TLS behaviour for instance

# What options can be configured for SSL/TLS encryption?

## Options (persistent)
Certificate chain file
#mqtttlswebview.tls.cert-chain=""

# Certificate key file
#mqtttlswebview.tls.cert-key=""

# Password for the certificate key file
#mqtttlswebview.tls.cert-key-password=""

# CA-certificate file
#mqtttlswebview.tls.ca-cert-file=""

# CA-certificate directory
#mqtttlswebview.tls.ca-cert-dir=""

# Use default CA-certificate directory
#mqtttlswebview.tls.ca-use-default-cert-dir=false

# Cipher list (openssl syntax)
#mqtttlswebview.tls.cipher-list=""

# OR combined SSL/TLS options (openssl values)
#mqtttlswebview.tls.tls-options=0

# SSL/TLS initialization timeout in seconds
#mqtttlswebview.tls.init-timeout=10

# SSL/TLS shutdown timeout in seconds
#mqtttlswebview.tls.shutdown-timeout=2

# Server Name Indication (SNI) Certificates:
# sni = SNI of the virtual server
# <key> = {
#           "CertChain" -> value:PEM-FILE,
#           "CertKey" -> value:PEM-FILE,
#           "CertKeyPassword" -> value:TEXT,
#           "CaCertFile" -> value:PEM-FILE,
#           "CaCertDir" -> value:PEM-CONTAINER:DIR,
#           "UseDefaultCaDir" -> value:BOOLEAN [false],
#           "SslOptions" -> value:UINT
#         }
#mqtttlswebview.tls.sni-cert=""

# Force using of the Server Name Indication
#mqtttlswebview.tls.force-sni=false
