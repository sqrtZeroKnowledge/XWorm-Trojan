**Intro:** 

During my investigation to analyze a sample of the **XWorm Trojan**, I decided to learn more about its behavior in the wild and examine its builder. After obtaining the builder, I discovered a security vulnerability that could assist security analysts in disrupting the builder's functionality or causing a Denial of Service (DoS) of the XWorm RAT C2 panel.

To exploit the vulnerability, one would need the IP address of the C2 and the port for the reverse connection. It is possible to build the exploit using Visual Studio and modify the indicators of compromise (IOCs) to suit your needs.
For those seeking additional samples.

PoC Validation : https://packetstormsecurity.com/files/170981/XWorm-Trojan-2.1-NULL-Pointer-Dereference.html

Malware Bazzar : https://bazaar.abuse.ch/browse/signature/Xworm/

Resources such as screenshots of the Trojan may prove helpful:

![PoC](https://pbs.twimg.com/media/Fo2NTDBWIAEXB6t?format=png&name=900x900)

Crash PoC

![Src: Cyble](https://i0.wp.com/blog.cyble.com/wp-content/uploads/2022/08/Figure-1-Darkweb-Post-for-XWorm.png?resize=609,1024&ssl=1)

XSS.IS FORUM

![Developer Website](https://i0.wp.com/blog.cyble.com/wp-content/uploads/2022/08/Figure-2-Post-by-The-Malicious-Program-Developer.png?resize=1024,722&ssl=1)

Cyble - Archvie.
