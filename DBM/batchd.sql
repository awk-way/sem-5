-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 25, 2025 at 07:01 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `batchd`
--

-- --------------------------------------------------------

--
-- Table structure for table `apply`
--

CREATE TABLE `apply` (
  `sid` int(11) NOT NULL,
  `cname` varchar(25) NOT NULL,
  `major` varchar(30) NOT NULL,
  `decision` varchar(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `apply`
--

INSERT INTO `apply` (`sid`, `cname`, `major`, `decision`) VALUES
(101, 'GEC', 'Computer Science', 'Y'),
(101, 'PCCE', 'Mechanical', 'N'),
(102, 'BITS', 'Civil', 'N'),
(102, 'NIT', 'Electrical', 'Y'),
(103, 'BITS', 'Electronics', 'Y'),
(103, 'IIT', 'Computer Science', 'Y'),
(104, 'GEC', 'IT', 'Y'),
(104, 'PCCE', 'Civil', 'N'),
(105, 'IIT', 'Mechanical', 'Y'),
(105, 'NIT', 'Aerospace', 'N'),
(106, 'BITS', 'Computer Science', 'Y'),
(106, 'PCCE', 'Electrical', 'N'),
(107, 'GEC', 'Civil', 'Y'),
(108, 'NIT', 'Electronics', 'Y'),
(110, 'IIT', 'Chemical', 'N');

-- --------------------------------------------------------

--
-- Table structure for table `bookadoption`
--

CREATE TABLE `bookadoption` (
  `book_isbn` int(11) NOT NULL,
  `courseid` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `bookadoption`
--

INSERT INTO `bookadoption` (`book_isbn`, `courseid`) VALUES
(1001, 2),
(1001, 5),
(1002, 1),
(1002, 5),
(1003, 3),
(1004, 4),
(1004, 5),
(1005, 1),
(1006, 1),
(1006, 2),
(1007, 2),
(1007, 3),
(1008, 3),
(1009, 4),
(1010, 4);

-- --------------------------------------------------------

--
-- Table structure for table `college`
--

CREATE TABLE `college` (
  `cname` varchar(25) NOT NULL,
  `state` varchar(20) NOT NULL,
  `enrollment` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `college`
--

INSERT INTO `college` (`cname`, `state`, `enrollment`) VALUES
('BITS', 'Goa', 5000),
('GEC', 'Goa', 6000),
('IIT', 'Mumbai', 12000),
('NIT', 'Haryana', 8000),
('PCCE', 'Goa', 2500);

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `courseid` int(11) NOT NULL,
  `title` varchar(25) NOT NULL,
  `dept_name` varchar(20) DEFAULT NULL,
  `credits` tinyint(4) DEFAULT NULL,
  `cname` varchar(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`courseid`, `title`, `dept_name`, `credits`, `cname`) VALUES
(1, 'OS', 'CS', 4, 'GEC'),
(2, 'DBMS', 'CS', 3, 'PCCE'),
(3, 'WT', 'CS', 3, 'NIT'),
(4, 'GT', 'CS', 2, 'IIT'),
(5, 'ISOH', 'Mechanical', 3, 'BITS');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `sid` int(11) NOT NULL,
  `sname` varchar(25) NOT NULL,
  `gpa` float(5,2) DEFAULT NULL,
  `sizeHS` int(11) DEFAULT NULL,
  `bdate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`sid`, `sname`, `gpa`, `sizeHS`, `bdate`) VALUES
(101, 'Aarav', 8.20, 45000, '2002-05-14'),
(102, 'Ishita', 7.60, 32000, '2003-09-21'),
(103, 'Rohan', 8.90, 50000, '2001-11-30'),
(104, 'Sneha', 7.40, 28000, '2002-07-19'),
(105, 'Vedant', 9.10, 60000, '2001-03-11'),
(106, 'Ananya', 8.00, 35000, '2003-02-25'),
(107, 'Kunal', 7.20, 40000, '2002-08-05'),
(108, 'Meera', 8.70, 30000, '2001-12-17'),
(109, 'Yusuf', 7.90, 27000, '2003-06-09'),
(110, 'Vaishnavi', 8.50, 33000, '2002-01-28');

-- --------------------------------------------------------

--
-- Table structure for table `taken`
--

CREATE TABLE `taken` (
  `sid` int(11) NOT NULL,
  `courseid` int(11) NOT NULL,
  `grade` varchar(2) DEFAULT 'AA'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `taken`
--

INSERT INTO `taken` (`sid`, `courseid`, `grade`) VALUES
(101, 1, '9'),
(102, 2, '8'),
(103, 3, '10'),
(104, 4, '7'),
(105, 5, '8'),
(106, 1, '9'),
(107, 2, '7'),
(108, 3, '8'),
(109, 4, '9'),
(110, 5, '10');

-- --------------------------------------------------------

--
-- Table structure for table `textbook`
--

CREATE TABLE `textbook` (
  `book_isbn` int(11) NOT NULL,
  `book_title` varchar(25) NOT NULL,
  `author` varchar(20) DEFAULT NULL,
  `publisher` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `textbook`
--

INSERT INTO `textbook` (`book_isbn`, `book_title`, `author`, `publisher`) VALUES
(1001, 'Database System Concepts', 'Korth', NULL),
(1002, 'Operating System Concepts', 'Silbersch', NULL),
(1003, 'Web Technologies', 'Schneider', NULL),
(1004, 'Computer Networks', 'Tanenbaum', NULL),
(1005, 'Data Structures', 'Sahni', NULL),
(1006, 'Algorithms', 'Cormen', NULL),
(1007, 'Database Management', 'Korth', NULL),
(1008, 'Internet Security', 'Stallings', NULL),
(1009, 'Graph Theory', 'Bondy', NULL),
(1010, 'Cryptography', 'Menezes', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `apply`
--
ALTER TABLE `apply`
  ADD PRIMARY KEY (`sid`,`cname`,`major`);

--
-- Indexes for table `bookadoption`
--
ALTER TABLE `bookadoption`
  ADD PRIMARY KEY (`book_isbn`,`courseid`),
  ADD KEY `courseid` (`courseid`);

--
-- Indexes for table `college`
--
ALTER TABLE `college`
  ADD PRIMARY KEY (`cname`);

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`courseid`),
  ADD UNIQUE KEY `us` (`title`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`sid`);

--
-- Indexes for table `taken`
--
ALTER TABLE `taken`
  ADD PRIMARY KEY (`sid`,`courseid`),
  ADD KEY `courseid` (`courseid`);

--
-- Indexes for table `textbook`
--
ALTER TABLE `textbook`
  ADD PRIMARY KEY (`book_isbn`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bookadoption`
--
ALTER TABLE `bookadoption`
  ADD CONSTRAINT `bookadoption_ibfk_1` FOREIGN KEY (`book_isbn`) REFERENCES `textbook` (`book_isbn`),
  ADD CONSTRAINT `bookadoption_ibfk_2` FOREIGN KEY (`courseid`) REFERENCES `course` (`courseid`);

--
-- Constraints for table `taken`
--
ALTER TABLE `taken`
  ADD CONSTRAINT `taken_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `student` (`sid`),
  ADD CONSTRAINT `taken_ibfk_2` FOREIGN KEY (`courseid`) REFERENCES `course` (`courseid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
