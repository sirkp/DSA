# larger Responses
def largerResponse(filename):
    file = open(filename, 'r');
    n = 0;
    sum = 0;
    for line in file:
        words = line.split();
        bytes = int(words[-1]);
        if(bytes>5000):
            n += 1;
            sum += bytes
    file.close();

    file = open("bytes_"+filename, "w");
    file.write(str(n)+"\n");
    file.write(str(sum)+"\n");# remove "\n" if not accepted
    

largerResponse(filename);
