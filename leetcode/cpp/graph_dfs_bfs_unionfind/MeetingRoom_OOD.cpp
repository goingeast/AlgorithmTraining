// PriorityQueue + Assign Room + In-room Merge Intervals
class Solution {
    class Room {
        int name, end;
        Room(int name, int end) {
            this.name = name;
            this.end = end;
        }
    }
    
    public int minMeetingRooms(Interval[] intervals) {
        Arrays.sort(intervals, new Comparator<Interval>(){
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        PriorityQueue<Room> pq = new PriorityQueue<>(new Comparator<Room>(){
            public int compare(Room a, Room b) {
                return a.end - b.end;
            }
        });
        List<List<Interval>> rec = new ArrayList<>();
        for (Interval interval : intervals) {
            Room cur = null;
            if (pq.isEmpty() || pq.peek().end > interval.start) {
                cur = new Room(pq.size(), 0);
                rec.add(new ArrayList<>());
            } else cur = pq.poll();
            cur.end = interval.end;
            rec.get(cur.name).add(interval);
            pq.add(cur);
        }
        mergeInterval(rec);
        return pq.size();
    }
    
    private void mergeInterval(List<List<Interval>> rec) {
        for (int i = 0; i < rec.size(); i ++) {
            if (rec.get(i).isEmpty()) continue;
            List<Interval> tmp = new ArrayList<>();
            Interval last = rec.get(i).get(0);
            for (int j = 1; j < rec.get(i).size(); j ++)
                if (last.end < rec.get(i).get(j).start) {
                    tmp.add(last);
                    last = rec.get(i).get(j);
                } else last.end = rec.get(i).get(j).end;
            tmp.add(last);
            rec.set(i, tmp);
        }
        for (List<Interval> room : rec) {
            System.out.print("[");
            for (Interval interval : room)
                System.out.print("[" + interval.start + ", " + interval.end + "], ");
            System.out.println("]");
        }
    }
}